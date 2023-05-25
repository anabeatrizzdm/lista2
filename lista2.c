#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PROFESSORES 3
#define MAX_DISCIPLINAS 2
#define MAX_ESTUDANTES 15

struct Professor {
    char nome[50];
    int funcional;
    char titulacao[20];
};

struct Estudante {
    char nome[50];
    int matricula;
    int idade;
};

struct Disciplina {
    char nome[50];
    int codigo;
    int carga_horaria;
    struct Professor professor_responsavel;
    struct Estudante estudantes[MAX_ESTUDANTES];
    int num_estudantes;
};

void bubbleSort(struct Estudante *estudantes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (estudantes[j].idade > estudantes[j + 1].idade) {
                // Troca de posição
                struct Estudante temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int le_valida_idade() {
    int idade;
    do {
        printf("Idade: ");
        scanf("%d", &idade);
        if (idade < 16 || idade > 26) {
            printf("Idade inválida! Digite uma idade entre 16 e 26.\n");
        }
    } while (idade < 16 || idade > 26);
    return idade;
}

int main() {
    struct Professor professores[MAX_PROFESSORES];
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
    int num_estudantes = 0;

    // Cadastro dos professores
    for (int i = 0; i < MAX_PROFESSORES; i++) {
        printf("\nProfessor %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", professores[i].nome);
        printf("Funcional: ");
        scanf("%d", &professores[i].funcional);
        printf("Titulação (especialista, mestre ou doutor): ");
        scanf("%s", professores[i].titulacao);
    }

    // Cadastro das disciplinas
    for (int i = 0; i < MAX_DISCIPLINAS; i++) {
        printf("\nDisciplina %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", disciplinas[i].nome);
        printf("Código: ");
        scanf("%d", &disciplinas[i].codigo);
        printf("Carga horária: ");
        scanf("%d", &disciplinas[i].carga_horaria);
        printf("Professor responsável (1 a %d): ", MAX_PROFESSORES);
        int indice_professor;
        scanf("%d", &indice_professor);
        if (indice_professor >= 1 && indice_professor <= MAX_PROFESSORES) {
            disciplinas[i].professor_responsavel = professores[indice_professor - 1];
        } else {
            printf("Opção inválida!\n");
            return 0;
        }
        disciplinas[i].num_estudantes = 0;
    }

    // Cadastro dos estudantes
    for (int i = 0; i < MAX_DISCIPLINAS; i++) {
        printf("\n### Cadastro de Estudantes para a Disciplina %d ###\n", i + 1);
        for (int j = 0; j < MAX_ESTUDANTES; j++) {
            if (disciplinas[i].num_estudantes >= MAX_ESTUDANTES) {
                printf("Limite máximo de estudantes atingido para a disciplina %d.\n", i + 1);
                break;
            }

            printf("\nEstudante %d:\n", j + 1);
            printf("Nome: ");
            scanf("%s", disciplinas[i].estudantes[j].nome);
            printf("Matrícula: ");
            scanf("%d", &disciplinas[i].estudantes[j].matricula);
            disciplinas[i].estudantes[j].idade = le_valida_idade();

            disciplinas[i].num_estudantes++;
        }
    }

    // Relatório dos alunos matriculados na primeira disciplina (ordenados por idade)
    bubbleSort(disciplinas[0].estudantes, disciplinas[0].num_estudantes);

    printf("\nRelatório de Alunos Matriculados na Primeira Disciplina (Ordenados por Idade):\n");
    printf("Código da Disciplina: %d\n", disciplinas[0].codigo);
    printf("Nome do Professor: %s\n", disciplinas[0].professor_responsavel.nome);
    printf("\n");

    printf("Codigo_disciplina\tNome_professor\tNome_estudante\tIdade_estudante\n");
    for (int i = 0; i < disciplinas[0].num_estudantes; i++) {
        printf("%d\t\t\t%s\t\t%s\t\t%d\n", disciplinas[0].codigo, disciplinas[0].professor_responsavel.nome,
               disciplinas[0].estudantes[i].nome, disciplinas[0].estudantes[i].idade);
    }

    // Relatório dos alunos matriculados na segunda disciplina (ordenados por idade em ordem decrescente)
    bubbleSort(disciplinas[1].estudantes, disciplinas[1].num_estudantes);

    printf("\nRelatório de Alunos Matriculados na Segunda Disciplina (Ordenados por Idade em Ordem Decrescente):\n");
    printf("Código da Disciplina: %d\n", disciplinas[1].codigo);
    printf("Nome do Professor: %s\n", disciplinas[1].professor_responsavel.nome);
    printf("\n");

    printf("Codigo_disciplina\tNome_professor\tNome_estudante\tIdade_estudante\n");
    for (int i = 0; i < disciplinas[1].num_estudantes; i++) {
        printf("%d\t\t\t%s\t\t%s\t\t%d\n", disciplinas[1].codigo, disciplinas[1].professor_responsavel.nome,
               disciplinas[1].estudantes[i].nome, disciplinas[1].estudantes[i].idade);
    }

    return 0;
}





