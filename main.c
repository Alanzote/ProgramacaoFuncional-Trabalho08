// Aluno: Alan Renato Bunese
// Matéria: Programação Funcional
// Professor: Frank Alcantara

// Precisamos incluir o stdio.h, para utilizar prinf.
#include <stdio.h>

// Precisamos incluir o stdlib.h, para utilizar malloc.
#include <stdlib.h>

// Também precisamos da string.h para chamar o strcmp
// que vai ser utilizado na questão 5 caso a nota de um
// aluno seja igual a outra, aí ordenamos pelo nome.
#include <string.h>

/* 1.
 * Usando os conceitos de programação funcional e considerando o universo dos números
 * inteiros, implemente a função foldr em Pyton, C ou C++ 20 tomando como base o
 * funcionamento desta função em Haskell. Sem, é claro, usar qualquer função, objeto
 * ou biblioteca disponíveis na linguagem que você escolher.
 */
int Foldr(int (*func)(int, int), int init, int* lst, int len) {
    // Se a lista for vazia, retorna o valor inicial.
    if (lst == NULL || len <= 0)
        return init;
    
    // Chamamos a função recursivamente, passando o próximo elemento da lista
    // com o resultado adquirido até o momento.
    return func(lst[0], Foldr(func, init, lst + 1, len - 1));
}

// Para testar o foldr, aqui está uma função que soma dois números.
int Sum(int a, int b) {
    return a + b;
}

// Para testar com outra função, aqui está uma função que multiplica dois números.
int Mult(int a, int b) {
    return a * b;
}

/* 2.
 * Usando os conceitos de programação funcional e considerando o universo dos números
 * inteiros, implemente a função abs em Python, C ou C== 20 que devolva o valor absoluto
 * de um número dado. Sem, é claro, usar qualquer função, objeto ou biblioteca disponíveis
 * na linguagem que você escolher.
 */
int Abs(int n) {
    // Se N for numero negativo, retornamos -n
    // caso contrário, é o próprio n.
    return n < 0 ? -n : n;
}

/* 3.
 * Usando os conceitos de programação funcional e considerando o universo dos números
 * inteiros, implemente a função media em Python, C ou C++ 20 que devolva a média
 * aritmética entre dois números dados. Sem, é claro, usar qualquer função, objeito, ou
 * biblioteca disponíveis na linguagem que você escolher.
 */
float Media(int a, int b) {
    return (a + b) / 2.f;
}

/* 4.
 * Usando os conceitos de programação funcional e a linguagem Python, C ou C++ 20 escreva
 * uma função que devolva a lista de todos os números de Fibonacci até um valor dado
 * considerando que a sequência de Fibonacci começa em zero. Sem, é claro, usar qualquer função,
 * objeto, ou biblioteca disponíveis na linguagem que você escolher.
 */
int* Fibonacci(int n) {
    // Não calculamos Fibonacci de 
    if (n < 0)
        return NULL;

    // Primeiros, reservamos a memória para o nosso vetor.
    int* fib = malloc(sizeof(int) * (n + 1));

    // Fibonacci de 0 vai retornar 0.
    if (n >= 0)
        fib[0] = 0;

    // Fibonacci de 1 vai retornar 0 e 1.
    if (n >= 1)
        fib[1] = 1;
    
    // Para os demais índices... calcular o fibonacci.
    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    // Retornar o fibonacci.
    return fib;
}

/* 5.
 * Você tem uma lista de tuplas onde o primeiro campo é o nome de um aluno e o segundo
 * sua nota. Crie uma função, usando Python, C ou C++ 20 e os conceitos de programação
 * funcional para criar uma função que ordene listas de tuplas, como a tupla descrita
 * neste enunciado. Sem, é claro, usar qualquer função, objeto, ou biblioteca disponíveis
 * na linguagem que você escolher.
 */

// Estrutura da Nossa Tupla de Aluno.
// Não temos Tuplas em C puro, então vamos usar um struct.
typedef struct {
    // O Nome do Aluno.
    char* Nome;

    // A Nota dele.
    int Nota;
} Aluno;

// Função de Comparação de Alunos.
int CompararAlunos(Aluno* a, Aluno* b) {
    // Se as notas forem iguais, vamos comparar os nomes.
    if (a->Nota == b->Nota)
        return strcmp(a->Nome, b->Nome);

    // Se a nota de A for maior que a de B, retornamos 1.
    if (a->Nota > b->Nota)
        return 1;

    // Se a nota de A for menor que a de B, retornamos -1.
    return -1;
}

// Função de Ordenação de Alunos.
void OrdenarAlunos(Aluno* alunos, int n) {
    // Ordenamos usando quick sort a função de comparação
    // de alunos que criamos anteriormente.
    qsort(alunos, n, sizeof(Aluno), CompararAlunos);
}

// Função Main.
int main(int argc, char** argv) {

    {
        // Notificar que é teste da questão 1.
        printf("-- Testando Questão 1 --\n");

        // Criar uma lista de números.
        int lst[] = { 1, 2, 3, 4, 5 };

        // Testar a soma, começando em 10.
        printf("Soma: %d\n", Foldr(Sum, 10, lst, 5));

        // Testar a multiplicação, multiplicando por 2.
        printf("Multiplicação: %d\n", Foldr(Mult, 2, lst, 5));
    }

    {
        // Notificar que é teste da questão 2.
        printf("-- Testando Questão 2 --\n");

        // Testar o valor absoluto de -10.
        printf("Valor Absoluto de -10: %d\n", Abs(-10));

        // Testar o valor absoluto de 10.
        printf("Valor Absoluto de 10: %d\n", Abs(10));
    }

    {
        // Notificar que é teste da questão 3.
        printf("-- Testando Questão 3 --\n");

        // Testar a média de 10 e 20.
        printf("Média de 10 e 20: %f\n", Media(10, 20));

        // Testar a média de 35 e 60.
        printf("Média de 35 e 60: %f\n", Media(35, 60));
    }

    {
        // Notificar que é teste da questão 4.
        printf("-- Testando Questão 4 --\n");

        // Testar o Fibonacci de 10.
        int* fib = Fibonacci(10);

        // Imprimir o Fibonacci de 10.
        for (int i = 0; i < 10; i++)
            printf("%d ", fib[i]);

        // Pular uma linha no final para ficar bonito.
        printf("\n");
    }

    {
        // Notificar que é teste da questão 5.
        printf("-- Testando Questão 5 (Ordem será Crescente) --\n");

        // Criamos um vetor de alunos.
        // Temos 12 alunos neste lista.
        Aluno alunos[] = {
            { "João", 10 },
            { "Maria", 10 },
            { "Pedro", 9 },
            { "José", 8 },
            { "Ana", 7 },
            { "Paulo", 6 },
            { "Carlos", 5 },
            { "Ricardo", 4 },
            { "Rafael", 3 },
            { "Rafaela", 2 },
            { "Rafael", 1 },
            { "Rafaela", 0 },
        };

        // Ordenamos os alunos.
        OrdenarAlunos(alunos, 12);

        // Imprimimos os alunos.
        for (int i = 0; i < 12; i++)
            printf("%s - %d\n", alunos[i].Nome, alunos[i].Nota);
    }

    // Deu tudo certo!
    return 0;
}
