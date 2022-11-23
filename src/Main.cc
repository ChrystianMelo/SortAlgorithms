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
#include <fstream>
#include <ctime>
#include <utility>

#include "msgassert.h"

#include "QuickSortUtils.h"
#include "Sorting.h"

//#include "memlog.h"
enum SortType
{
    Recursivo = 1,
    Mediana = 2,
    Selecao = 3,
    NaoRecursivo = 4,
    EmpilhaInteligente = 5
};

/**
 * @brief Le as opcoes da linha de comando e inicializa variaveis
 *
 * @param argv Argumentos passados na execução.
 * @param argc Quantidade de argumentos.
 */
void parse_args(char **argv, int argc, std::string *inputFilename, std::string *outputFilename, int *sortType, int *s, int *k, int *m)
{
    std::string command(argv[0]); //  'quicksort'

    for (int i = 1; i < argc; i++)
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
        else if (arg.compare("-v") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");

            std::string arg(argv[i + 1]);
            *sortType = std::atoi(arg.c_str());
            i++;
        }
        else if (arg.compare("-v") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");

            std::string arg(argv[i + 1]);
            *sortType = std::atoi(arg.c_str());
            i++;
        }
        else if (arg.compare("-s") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");

            std::string arg(argv[i + 1]);
            *s = std::atoi(arg.c_str());
            i++;
        }
        else if (arg.compare("-k") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");

            std::string arg(argv[i + 1]);
            *k = std::atoi(arg.c_str());
            i++;
        }
        else if (arg.compare("-m") == 0)
        {
            erroAssert(argc > i, "Erro: Os argumentos passados não são suficientes.");

            std::string arg(argv[i + 1]);
            *m = std::atoi(arg.c_str());
            i++;
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
std::pair<int, int> selectionSort(int arr[], int start, int end, int m)
{
    std::pair<int, int> info = QuickSortUtils::qsortSelection(arr, start, end, m);

    if (!QuickSortUtils::isSorted(arr, start, end))
    {
        std::pair<int, int> info1 = QuickSortUtils::qsortSelection(arr, start, end, 1);
        info.first += info1.first;
        info.second += info1.second;
    }

    // erroAssert(QuickSortUtils::isSorted((arr, start, end), "Não foi possivel ordenar");

    return info;
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
    // Processa os argumentos de entrada.
    std::string inputFilename;
    std::string outputFilename;

    int sortType, k, m, s;
    // Le os argumentos de entrada do programa.
    parse_args(argv, argc, &inputFilename, &outputFilename, &sortType, &s, &k, &m);

    // Trata possiveis erros com as entradas.
    erroAssert(!inputFilename.empty(), "O arquivo de entrada não é válido.");
    erroAssert(!outputFilename.empty(), "O arquivo de saida não é válido.");

    std::ofstream oFile;
    oFile.open(outputFilename);

    {
        // Lê o arquivo.
        std::ifstream myfile(inputFilename);
        erroAssert(myfile.is_open(), "Não foi possivel abrir o arquivo.");

        std::string line;
        getline(myfile, line);
        int loop = std::atoi(line.c_str());

        for (int i = 0; i < loop; i++)
        {
            oFile << "---------- " << i + 1 << "° Sort "
                  << "----------" << std::endl;
            std::string line;
            getline(myfile, line);
            int n = std::atoi(line.c_str());
            int *vet;

            vet = (int *)malloc(n * sizeof(int));

            for (int i = 0; i < n; i++)
                vet[i] = (rand() % s);

            const clock_t begin_time = std::clock();
            std::pair<int, int> info;
            switch (sortType)
            {
            case 1:
                info = QuickSortUtils::qsortRecursive(vet, 0, n - 1);
                break;
            case 2:
                info = QuickSortUtils::qsortMediana(vet, 0, n - 1);
                break;
            case 3:
                info = selectionSort(vet, 0, n - 1, 2);
                break;
            case 4:
                info = QuickSortUtils::qsortIterative(vet, 0, n - 1);
                break;
            case 5:
                info = QuickSortUtils::qsortEmplhaInteligente(vet, 0, n - 1);
                break;
            }
            float diff((std::clock() - begin_time));
            oFile << "Coping    : " << info.first << " copies." << std::endl;
            oFile << "Comparing : " << info.second << " comparisons." << std::endl;
            oFile << "Timing    : " << diff << " clocks." << std::endl;
        }
        myfile.close();
    }
    oFile.close();

    // Inicia o mem log.
    // iniciaMemLog(logFilename.c_str());

    /*/ Define o memlog de acordo com o padrão de acesso.
    if (accessPattern)
        ativaMemLog();
    else
        desativaMemLog();*/

    // Do something.

    // Conclui registro de acesso.
    // finalizaMemLog();

    return 0;
}