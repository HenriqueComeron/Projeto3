#include "proj.h"
#include <stdio.h>
#include <string.h>



int criarTarefa(ListaDeTarefas *lt){

    // Abrindo o arquivo
    FILE *f = fopen("arquivo.bin", "ab");

    // Transformando Struct em local
    Tarefa novatarefa;

    // Verificação de Limite
    if (lt->qtd >= 100){
        printf("Limite maximo de tarefas atingido, apague uma antes de continuar\n");
        fclose(f);
        return 1;
    }

    // Pedindo informações basicas
    printf("De uma Categoria a sua tarefa: \n");
    scanf("%d",&novatarefa.categoria);

    printf("Descreva sua tarefa: \n");
    scanf("%d",&novatarefa.descricao);

    printf("Qual a prioridade (de 0 a 10): \n");
    scanf("%d",&novatarefa.prioridade);

    printf("Qual o estado da tarefa (1, 2 ou 3)? \n");
    scanf("%d", &novatarefa.estado);

    // Contando o número de tarefas
    lt->tarefas[lt->qtd] = novatarefa;
    lt->qtd++;

    return 0;

}

int deletarTarefa(ListaDeTarefas *lt){

    int resposta;

    // Mensagem para o usuário
    printf("Qual tarefa deseja deletar?\n");

    // Scan para ver a resposta do usuario
    scanf("%d",&resposta);

    // Verificar se o número fornecido é válido
    if (resposta >= 0 && resposta < lt->qtd) {
        // Remover a tarefa da lista
        for (int i = resposta; i < lt->qtd - 1; i++) {
            lt->tarefas[i] = lt->tarefas[i + 1];
        }
        lt->qtd--;
        printf("Tarefa excluida com sucesso\n");

    } else {
        printf("Numero de tarefa invalido\n");
    }

    return 0;

}

int listarTarefas(ListaDeTarefas lt) {
    int prioridadeescolhida;
    int estadoescolhido;
    int i = 0;
    int escolha;
    char categoriaescolhida[100];

    // Mensagem para o usuario
    printf("Deseja listar as tarefas com qual filtro?\n");
    printf("1 para filtrar por prioridade. \n");
    printf("2 para filtrar por estado. \n");
    printf("3 para filtrar por categoria. \n");
    printf("4 para filtrar por prioridade e categoria. \n");
    printf("5 para listar todas. \n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Digite a prioridade que deve ser listada: ");
        scanf("%d", &prioridadeescolhida);
        while (i < lt.qtd) {
            if (lt.tarefas[i].prioridade == prioridadeescolhida) {
                printf("Numero da Tarefa: %d\n", i);
                printf("Categoria: %s", lt.tarefas[i].categoria);
                printf("Descricao: %s", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                printf("Estado: %d\n", lt.tarefas[i].estado);

            }
            i++;
        }
    }
        if (escolha == 2) {
            printf("Digite o estado que deve ser listado: ");
            scanf("%d", &estadoescolhido);
            while (i < lt.qtd) {
                if (lt.tarefas[i].estado == estadoescolhido) {
                    printf("Numero da Tarefa: %d\n", i);
                    printf("Categoria: %s", lt.tarefas[i].categoria);
                    printf("Descricao: %s", lt.tarefas[i].descricao);
                    printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                    printf("Estado: %d\n", lt.tarefas[i].estado);
                }
                i++;
            }
        }
        if (escolha == 3) {
            printf("Digite a categoria que deve ser listada: ");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            fgets(categoriaescolhida, sizeof(categoriaescolhida), stdin);
            while (i < lt.qtd) {
                if (strcmp(lt.tarefas[i].categoria, categoriaescolhida) == 0) {
                    printf("Numero da Tarefa: %d\n", i);
                    printf("Categoria: %s", lt.tarefas[i].categoria);
                    printf("Descricao: %s", lt.tarefas[i].descricao);
                    printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                    printf("Estado: %d\n", lt.tarefas[i].estado);
                }
                i++;
            }
        }
        if (escolha == 4) {
            printf("Digite a categoria e prioridade que devem ser listados: ");
            printf("Categoria: \n");
            scanf("%s", &categoriaescolhida);
            printf("Prioridade: \n");
            scanf("%d", &prioridadeescolhida);
            while (i < lt.qtd) {
                if (strcmp(lt.tarefas[i].categoria, categoriaescolhida) == 0 &&
                    lt.tarefas[i].prioridade == prioridadeescolhida) {
                    printf("Numero da Tarefa: %d\n", i);
                    printf("Categoria: %s", lt.tarefas[i].categoria);
                    printf("Descricao: %s", lt.tarefas[i].descricao);
                    printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                    printf("Estado: %d\n", lt.tarefas[i].estado);
                }
                i++;
            }
        }
        if (escolha == 5) {
            while (i < lt.qtd) {
                printf("Numero da Tarefa: %d\n", i);
                printf("Categoria: %s", lt.tarefas[i].categoria);
                printf("Descricao: %s", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                printf("Estado: %d\n", lt.tarefas[i].estado);

                i++;
            }
        }
        return 0;
    }

    void printMenu() {
        printf("Menu:\n ");
        printf("1. Criar Tarefa\n ");
        printf("2. Deletar Tarefa\n ");
        printf("3. Listar Tarefas\n ");
        printf("4. Alterar Tarefa\n ");
        printf("5. Exportar Tarefas\n ");

    }
    int salvarLista(ListaDeTarefas lt, char nome[]) {

        // Abrindo o arquivo como write
        FILE *f = fopen("arquivo.bin", "wb");
        //

        if (f == NULL) {
            return 1;
        }
        // Escrevendo a lista atualizada no arquivo
        fwrite(&lt, sizeof(ListaDeTarefas), 1, f);
        //

        // Fechando o arquivo
        fclose(f);
        //

        // Indicação de Sucesso
        return 0;
    }


    int carregarLista(ListaDeTarefas *lt, char nome[]) {

        // Abrindo o arquivo como read
        FILE *f = fopen("arquivo.bin", "rb");
        //

        if (f == NULL)
            return 1;

        //Loop de repetição para leitura de cada Tarefa dentro da ListaDeTarefas no endereço de tarefalida
        fread(lt, sizeof(ListaDeTarefas), 1, f);
        //

        //Fecha o arquivo
        fclose(f);
        //

        // Indicação de Sucesso
        return 0;
    }
