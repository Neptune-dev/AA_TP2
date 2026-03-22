#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "include/test.h"
#include "include/sequence.h"

// initialise l'aléatoire, nécessaire pour randomiseTable eg
void initRandom ()
{
    srand(time(NULL));
}

void freeResults(double** resultsTable, int func)
{
    for (int i = 0; i < func; i++)
    {
        free(resultsTable[i]);
    }
    free(resultsTable);
}

// met les n premieres valeurs de t à un entier aléatoire entre -maxPositiveValue et +maxPositiveValue
// à besoin d'être initialisé une unique fois avant utilisation, avec initRandom, si l'utilisateur utilise cette fonction hors de testRoutine
void randomiseTable (int t[], int n, int maxPositiveValue)
{
    for (int  i = 0; i < n; i++)
    {
        t[i] = (rand() % (2 * maxPositiveValue)) - maxPositiveValue;
    }
}

// renvoie le temps d'execution de submaxMethod pour les arguments t et n, stocke le resultat de la methode dans methodResult
double testMethod(Seq (*submaxMethod)(int*, int), int t[], int n, Seq *methodResult)
{
    clock_t start, end;

    start = clock();

    *methodResult = submaxMethod(t, n);

    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// teste les methodes passées en paramètre pour des tableaux de valeurs aléatoires :
// le nombre de fonction est donné par le paramètre func
// la taille des tableau est croissante de 1 à maxTableSize
// les valeurs aléatoires sont comprise entre -n et +n
double** testRoutine (int maxTableSize, int n, int func, ...)
{
    initRandom();

    va_list args;
    va_start(args, func);

    int* sampleTable = (int*)malloc(maxTableSize * sizeof(int));
    if (sampleTable == NULL)
    {
        printf("Memory allocation failed\n");
        va_end(args);
        exit(1);
    }

    // on récupère toutes les fonctions passées en varargs
    SubmaxMethod* functions = (SubmaxMethod*)malloc(func * sizeof(SubmaxMethod));
    if (functions == NULL)
    {
        printf("Memory allocation failed\n");
        va_end(args);
        free(sampleTable);
        exit(1);
    }
    for (int i = 0; i < func; i++)
    {
        functions[i] = va_arg(args, SubmaxMethod);
    }

    // fin d'usage des arguments
    va_end(args);

    // tableau de résultat 2D : fonction x maxTableSize
    double** timeResults = (double**)malloc(func * sizeof(double*));
    if (timeResults == NULL)
    {
        printf("Memory allocation failed\n");
        free(functions);
        free(sampleTable);
        exit(1);
    }

    // 2e dimension
    for (int i = 0; i < func; i++)
    {
        timeResults[i] = (double*)malloc(maxTableSize * sizeof(double));
        if (timeResults[i] == NULL)
        {
            printf("Memory allocation failed\n");
            // free des cases précédentes en cas d'erreur
            for (int j = 0; j < i; j++) {
                free(timeResults[j]);
            }
            free(functions);
            free(timeResults);
            free(sampleTable);
            exit(1);
        }
    }

    // message à l'utilisateur
    printf("\n####################################################\n\n");
    printf("Parametres :\n- %d fonctions testees\n- %d tableaux aleatoires utilises\n- variables comprises entre -%d et +%d\n", func, maxTableSize, n, n);
    printf("\n####################################################\n");
    printf("\n                 [ TESTS EN COURS ]\n");
    printf("\n####################################################\n\n");
    printf("...\n");

    // serie de tests
    Seq resBuffer;
    for (int tableSize = 1; tableSize <= maxTableSize; tableSize++)
    {
        // msg
        printf("\033[F\033[K");
        printf(" >>> Test en cours pour les tableaux de taille %d\n", tableSize);

        randomiseTable(sampleTable, tableSize, n);

        for (int fun = 0; fun < func; fun++)
        {
            timeResults[fun][tableSize - 1] = testMethod(functions[fun], sampleTable, tableSize, &resBuffer);
        }
    }

    //msg
    printf("\nDone!\n");
    printf("\n####################################################\n\n");

    // nettoyage
    free(functions);
    free(sampleTable);

    return timeResults;
}

void printResults (double** results, int maxTableSize, int func)
{
    for (int tableSize = 1; tableSize <= maxTableSize; tableSize++)
    {
        printf("\nn = %d :\n", tableSize);
        for (int fun = 0; fun < func; fun++)
        {
            printf("f%d : %Lf\n", fun, results[fun][tableSize - 1]);
        }
    }
}

void printTable (int *t, int n, char* label)
{
    printf("%s : ", label);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

void exportResultsToCSV(double** results, int maxTableSize, int func, const char* filename)
{
    printf("Export des donnees...\n");
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    // labels
    fprintf(file, "n;");
    for (int i = 0; i < func; i++)
    {
        fprintf(file, "f%d", i);
        if (i < func - 1)
        {
                fprintf(file, ";");
        }
    }
    fprintf(file, "\n");

    // data
    char buffer[20];
    for (int i = 0; i < maxTableSize; i++)
    {
        fprintf(file, "%d;", i + 1);
        for (int j = 0; j < func; j++) {
            snprintf(buffer, sizeof(buffer), "%.2f", results[j][i]);

            // on remplace le pointpar une virgule
            for (char* p = buffer; *p; p++)
            {
                if (*p == '.')
                {
                    *p = ',';
                    break; // ya qu'une virgule par valeur
                }
            }

            fprintf(file, "%s", buffer);

            if (j < func - 1)
            {
                fprintf(file, ";");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Done!\n");
}