#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "agenda.h"

struct contato {
    char nome[50];
    char telefone[15];
    char email[50];
    struct contato* proximo;
};
struct agenda {
    CONTATO* inicio; // Na agenda ordenada, nao precisamos necessariamente do ponteiro "fim"
};

AGENDA* criar_agenda(){
    AGENDA* novo = (AGENDA*)malloc(sizeof(AGENDA));
    novo->inicio = NULL;
    return novo;
}

void adicionar_contato(AGENDA* agenda, char* NOME, char* TELEFONE, char* EMAIL){
    CONTATO* novo;
    CONTATO* anterior = NULL; // ponteiro para o elemento anterior ao atual (null)
    CONTATO* atual = agenda->inicio; // ponteiro para percorrer a lista (começa no inicio)
    while(atual!=NULL && strcmp(NOME,atual->nome)>0){ // O loop continua enquanto nao chega no fim da lista e enquando strcmp(A,B)>0, ou seja, A vem depois de B
        anterior = atual; //anterior avança
        atual = atual->proximo; // atual avanca
    }
    // O loop para em 2 condicoes: atual = NULL ou quando strcmp <= 0
    if(atual!= NULL && strcmp(NOME,atual->nome) == 0){
        printf("ERRO: Contato existente!\n");
        return;
    }
    novo = (CONTATO*)malloc(sizeof(CONTATO)); // Alocamos memoria para um novo no (novo)
    strcpy(novo->nome, NOME); //strcpy(destino,origem) = copia o NOME para novo->nome
    strcpy(novo->email, EMAIL);
    strcpy(novo->telefone, TELEFONE);
    if(anterior == NULL){ // se o loop parou e anterior == NULL, inserimos o elemento no inicio
        novo->proximo = agenda->inicio; // no novo e inserido no inicio | novo->proximo passa a ser a antiga cabeca
        agenda->inicio = novo; 
    }
    else{ //se anterior!=NULL, inserimos o elemento no meio da lista (entre anterior e atual)
        // ANTES DE INSERIR ELEMENTO: anterior->atual | DEPOIS: anterior->novo->atual
        novo->proximo = anterior->proximo; 
        anterior->proximo = novo;
    }
}

void remover_contato(AGENDA* agenda, char* NOME){
    CONTATO* anterior = NULL;
    CONTATO* atual = agenda->inicio;
    while(atual!= NULL && strcmp(NOME,atual->nome)!=0){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){ //nome nao encontrado na lista
        printf("Contato não encontrado!\n");
        return;
    }
    if(anterior == NULL){ //Se o anterior é null, o contato a ser removido e o primeiro (inicio)
        agenda->inicio = atual->proximo; // O inicio da agenda agora deve pular o atual e ir para o proximo
    }
    else{ // anterior!= NULL -> contato a ser retirado esta no meio da lista
        anterior->proximo = atual->proximo; // no anterior pula o atual e seu ponteiro proximo aponta para o atual-> proximo

    }
    free(atual);
}

CONTATO* buscar_contato(AGENDA* agenda, char* NOME){
    CONTATO* atual;
    for(atual = agenda->inicio; atual!=NULL; atual=atual->proximo){
        if(strcmp(NOME,atual->nome)==0){
            printf("\nDADOS DO CONTATO:\nNome: %s\nTelefone: %s\nEmail: %s\n",atual->nome,atual->telefone,atual->email);
            return atual;
        }
    }
    printf("\nContato nao encontrado!");

    return NULL;
}

void editar_contato(AGENDA* agenda, char* NOME){
    CONTATO* achei = buscar_contato(agenda,NOME); //busca o contato // Recebe o ENDEREÇO do contato na lista
    if(achei == NULL){ //se o contato nao for achado 
        return;
    }
    else{ // se o contato for achado
        printf("\nNovo telefone:");
        fgets(achei->telefone,15,stdin); //novo telefone
        achei->telefone[strcspn(achei->telefone,"\n")] = 0; //limpar o enter
        printf("Novo email:");
        fgets(achei->email,50,stdin); //novo email
        achei->email[strcspn(achei->email,"\n")] = 0; //limpar o enter
        printf("\nDados alterados com sucesso!\n");
        return;
    }
}

void listar_contato(AGENDA* agenda){
    if(agenda_vazia(agenda)){
        printf("\nA agenda esta vazia!\n");
    }
    CONTATO* atual;
    printf("____________________________");
    printf("\nCONTATOS (A-Z)\n");
    printf("____________________________\n");
    for(atual = agenda->inicio; atual!=NULL; atual=atual->proximo){
        printf("\nNome: %s\n",atual->nome);
        printf("Telefone: %s\n",atual->telefone);
        printf("Email: %s\n",atual->email);
        printf("------------------------------");
    }
}

int agenda_vazia(AGENDA* agenda){
    if(agenda->inicio == NULL)
        return 1;
    return 0;
}

void agenda_libera(AGENDA* agenda){
    CONTATO* atual = agenda->inicio;
    while(atual!=NULL){
        CONTATO* auxiliar = atual->proximo;
        free(atual);
        atual = auxiliar;
    }
    free(agenda);
}



