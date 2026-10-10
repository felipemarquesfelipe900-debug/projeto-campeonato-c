#include <stdio.h>
#include <string.h>

int main() {

// DECLARAÇÃO DAS ESTATISTICAS
    char *nomes[5] = {
        "corinthians",
        "palmeiras",
        "santos",
        "sao_paulo",
        "flamengo"
    };

// VARIÁVEIS
    int vitorias[5] = {0};
    int empates[5] = {0};
    int derrotas[5] = {0};
    int gols[5] = {0};
    int pontos[5] = {0};
    int gols_casa;
    int gols_fora;
    int time_casa;
    int time_fora;
    int temp;
    char *temp_nome;
    char busca[20];
    int encontrou;

    
// MENU PRINCIPAL
    int opcao;

        printf("\nTimes Cadastrados:\n");

        for (int i = 0; i < 5; i++) {
            printf("%d %s\n", i, nomes[i]);
        }

        printf("Menu Principal:\n\n 1- Cadastrar Resultados.\n 2- Mostrar Resultados.\n 3- Ordenar Classificacao.\n 4- Buscar Time.\n 5- Sair.\n");

    do {
//menu funcional
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
//cadastro de resultado
            printf("\nVoce escolheu cadastrar resultados.\n");

            printf("\nInforme o numero do time da casa: ");
            scanf("%d", &time_casa);

            printf("Informe o numero do time visitante: ");
            scanf("%d", &time_fora);

                if(time_casa < 0 || time_casa > 4 || time_fora < 0 || time_fora > 4) {
                    printf("\nTime Invalido, por favor selecione um time cadastrado(0-4)!\n");
                break;
                }

                if (time_casa == time_fora) {
                    printf("\nUm time nao pode jogar contra ele mesmo!\n");
                break;
                }

            printf( "\nInforme o placar do jogo:");
            scanf("%d %d", &gols_casa, &gols_fora);
                if (gols_casa < 0 || gols_fora < 0) {
                    printf("Resultados negativos sao invalidos!");
                break;
                }

//Resultado da partida      
        if ( gols_casa > gols_fora) {
            printf("\nVitoria do time da casa.\n\n");
        }

        else if (gols_casa < gols_fora) {
            printf("\nVitoria do time visitante.\n\n");
        }

        else {
            printf("\nHouve um empate\n\n");
        }

//registro de pontuação
        if (gols_casa > gols_fora) {
            vitorias[time_casa]++;
            derrotas[time_fora]++;
            pontos[time_casa] += 3;
        }

        else if (gols_casa < gols_fora) {
            derrotas[time_casa]++;
            vitorias[time_fora]++;
            pontos[time_fora] += 3;
        }

        else {
            empates[time_casa]++;
            empates[time_fora]++;
            pontos[time_casa] += 1;
            pontos[time_fora] += 1;
        }

// REGISTRO DE GOLS
            gols[time_casa] += gols_casa;
            gols[time_fora] += gols_fora;

        break;

        case 2:
// mostrar pontuação
            printf("\nVoce escolheu mostrar classificacao.\n");

            for (int i = 0; i < 5; i++) {
                printf("Time: %s\n", nomes[i]);

                printf("Pontuacao: %d pontos.\n", pontos[i]);
                printf("Vitorias: %d vitorias.\n", vitorias[i]);
                printf("Derrotas: %d derrotas.\n", derrotas[i]);
                printf("Empates: %d empates.\n", empates[i]);
                printf("Gols: %d gols.\n\n", gols[i]);
            }
            break;

        case 3:

            printf("\nVoce escolheu ordenar a classificacao.\n");
        
            for (int i = 0; i < 5; i++) {

                for (int j = i + 1;j < 5; j++) {

        
                    if (pontos[j] > pontos[i]) {
                        temp = pontos[i];
                        pontos[i] = pontos[j];
                        pontos[j] = temp;

                        temp = vitorias[i];
                        vitorias[i] = vitorias[j];
                        vitorias[j] = temp;

                        temp = derrotas[i];
                        derrotas[i] = derrotas[j];
                        derrotas[j] = temp;

                        temp = empates[i];
                        empates[i] = empates[j];
                        empates[j] = temp;

                        temp = gols[i];
                        gols[i] = gols[j];
                        gols[j] = temp;

                        temp_nome = nomes[i];
                        nomes[i] = nomes[j];
                        nomes[j] = temp_nome;

                    }
                }
            }  
//IMPRIMIR
            for (int i = 0; i < 5; i++) {
                printf("%d - %s | %d pts.\n", i + 1, nomes[i], pontos[i]);
            }
            break;

        case 4:

            encontrou = 0;

            printf("\nVoce escolheu buscar um time.\n");
        
            printf("\nDigite o nome do time que deseja buscar:");
            scanf("%19s", busca);

            for(int i = 0; i < 5; i++){
                if(strcmp(busca,nomes[i]) == 0) {
                    printf("Time Encontrado.\n");
                    printf("Time:%s\n - Pontos:%d\n - Vitorias:%d\n - Derrotas:%d\n - Empates:%d\n - Gols:%d\n\n", nomes[i], pontos[i], vitorias[i], derrotas[i], empates[i], gols[i]);
                    encontrou = 1;
                }
            }  

            if (encontrou == 0){
                 printf("Time nao encontrado.\n");
            }
            break;

        case 5:

            printf("Voce escolheu sair.");
            break;

            default:
                printf("Opcao invalida, selecione uma opcao de entre 1 e 5!");
                break;
        }

    } while (opcao != 5);

    return 0;
}