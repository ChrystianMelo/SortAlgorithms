/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 * @version 0.1
 * @date 2022-11-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "msgassert.h"

#include "QuickSortUtils.h"
#include "Sorting.h"

//#include "memlog.h"

/**
 * @brief Le as opcoes da linha de comando e inicializa variaveis
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
void parse_args(char **argv, int argc, std::string *inputFilename, std::string *outputFilename, std::string *logFilename, bool *accessPattern)
{
    for (int i = 0; i < argc; i++)
    {
        std::string arg(argv[i]);

        if (arg.compare("-i") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *inputFilename = arg;
            i++;
        }
        else if (arg.compare("-o") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *outputFilename = arg;
            i++;
        }
        else if (arg.compare("-p") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");
            std::string arg(argv[i + 1]);
            *logFilename = arg;
            i++;
        }
        else if (arg.compare("-l") == 0)
        {
            *accessPattern = true;
        }
    }
}

/**
    \brief Metodo temporário para assegurar a exatidão no processo de ordenação por seleção.

    \param arr		Array que será ordenado.
    \param start	Primeiro indice do array.
    \param end		Ultimo indice do array.
    \param m		Tamanho m.
**/
void selectionSort(int arr[], int start, int end, int m) {
    QuickSortUtils::qsortSelection(arr, start, end, m);
       
    if (!QuickSortUtils::isSorted(arr, start, end))
        QuickSortUtils::qsortSelection(arr, start, end, 1);

    //erroAssert(QuickSortUtils::isSorted((arr, start, end), "Não foi possivel ordenar");
}

/**
 * @brief Main
 *
 * @param argc
 * @param argv
 *      -i "nome do arquivo de entrada" (entrada em formato .ppm)
 *      -o "nome do arquivo de saída" (saída em formato .pgm)
 *      -p log.out (registro de desempenho)
 *      -l (padrão de acesso e localidade)
 * @return ** int
 */
int main(int argc, char *argv[])
{
    // Por padrão, se espera 4 entradas.
    // erroAssert(argc > 4, "Numero de argumentos minimo para execução não atingido.");

    // Processa os argumentos de entrada.
    std::string inputFilename;
    std::string outputFilename;
    std::string logFilename;
    bool accessPattern;

    // Le os argumentos de entrada do programa.
    //parse_args(argv, argc, &inputFilename, &outputFilename, &logFilename, &accessPattern);

    // Trata possiveis erros com as entradas.
    //erroAssert(!inputFilename.empty(), "O arquivo de entrada não é válido.");
    //erroAssert(!outputFilename.empty(), "O arquivo de saida não é válido.");
    //erroAssert(!logFilename.empty(), "O arquivo de log não é válido.");

    int n = 10;
    int *vet;

    vet = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Recursivamente----" << std::endl;
    QuickSortUtils::qsortRecursive(vet, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;
    
    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Mediana----" << std::endl;
    QuickSortUtils::qsortMediana(vet, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;

    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Seleção----" << std::endl;
    selectionSort(vet, 0, n - 1, 2);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;

    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Iteração----" << std::endl;
    QuickSortUtils::qsortIterative(vet, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;

    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Merge----" << std::endl;
    Sorting::mergeSort(vet, 0, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;

    for (int i = 0; i < n; i++) vet[i] = (rand() % 100);

    std::cout << "------Heap----" << std::endl;
    Sorting::heapSort(vet,n);
    for (int i = 0; i < n; i++)
        std::cout << vet[i] << std::endl;

    // Inicia o mem log.
    //iniciaMemLog(logFilename.c_str());

    /*/ Define o memlog de acordo com o padrão de acesso.
    if (accessPattern)
        ativaMemLog();
    else
        desativaMemLog();*/

    // Do something.

    // Conclui registro de acesso.
    //finalizaMemLog();

    return 0;
}