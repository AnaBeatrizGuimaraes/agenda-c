#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "agenda.h"

int main(){
    AGENDA* minha_agenda = criar_agenda();
    int opcao;
    char nome_aux[50];
    char tel_aux[15];
    char email_aux[50];
    do{
        printf("\n____________________________");
        printf("\nAGENDA TELEFONICA\n");
        printf("____________________________\n");
        printf("1.Adicionar contato\n");
        printf("2.Listar todos os contatos\n");
        printf("3.Buscar contato\n");
        printf("4.Editar contato\n");
        printf("5.Excluir contato\n");
        printf("6.Sair\n");
        printf("Digite o numero da opcao escolhida:");
        scanf("%d",&opcao);
        // --- LIMPEZA DE BUFFER CRITICA ---
        // consome o 'Enter' que sobrou do scanf anterior
        // Se nao fizer isso, o próximo fgets vai ler vazio!
        while (getchar() != '\n');
        
        switch (opcao){
        case 1:
            printf("\nDigite o nome:");
            fgets(nome_aux,50,stdin);
            nome_aux[strcspn(nome_aux,"\n")] = 0;

            printf("Digite o telefone:");
            fgets(tel_aux,15,stdin);
            tel_aux[strcspn(tel_aux,"\n")] = 0;

            printf("Digite o email:");
            fgets(email_aux,50,stdin);
            email_aux[strcspn(email_aux,"\n")] = 0;

            adicionar_contato(minha_agenda,nome_aux,tel_aux,email_aux);
            printf("\nContato adicionado!\n");
            break;

        case 2:
            listar_contato(minha_agenda);
            break;
        
        case 3:
            printf("\nDigite o nome do contato que deseja buscar:");
            fgets(nome_aux,50,stdin);
            nome_aux[strcspn(nome_aux,"\n")] = 0;
            buscar_contato(minha_agenda,nome_aux);
            break;
        
        case 4:
            printf("\nDigite o nome do contato que deseja editar:");
            fgets(nome_aux,50,stdin);
            nome_aux[strcspn(nome_aux,"\n")] = 0;
            editar_contato(minha_agenda,nome_aux);
            break;
        
        case 5:
            printf("\nDigite o nome do contato que deseja excluir:");
            fgets(nome_aux,50,stdin);
            nome_aux[strcspn(nome_aux,"\n")] = 0;
            remover_contato(minha_agenda,nome_aux);
            printf("\nContato removido!\n");
            break;
            
        case 6:
            printf("Finalizando a agenda...\n");
            break;
        
        default:
            printf("\nOpcao invalida! Digite um numero entre 1 e 6.\n");
            break;
        }
    }while(opcao!=6);

    agenda_libera(minha_agenda);
    return 0;
}