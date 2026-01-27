#ifndef AGENDA_H
#define AGENDA_H

typedef struct contato CONTATO;
typedef struct agenda AGENDA;

AGENDA* criar_agenda(); // inicializa uma agenda vazia

//Ela deve inserir um novo contato na lista mantendo a ordem alfabetica.
void adicionar_contato(AGENDA* agenda, char* NOME, char* TELEFONE, char* EMAIL);

//Busca um contato pelo nome e o remove da lista 
//Se o contato nao existir, exiba uma mensagem de "Contato nao encontrado".
void remover_contato(AGENDA* agenda, char* NOME);

//Percorre a lista procurando pelo nome exato.
//Se encontrar, exibe os dados (Telefone e Email) e retorna o ponteiro para aquele no.
//Se nao encontrar, exibe aviso e retorna NULL.
CONTATO* buscar_contato(AGENDA* agenda, char* NOME);

//Usa a funcao de busca para encontrar o contato.
//Se achar, permite que o usuario digite um novo telefone e novo email (o nome nao deve ser alterado para nao quebrar a ordem alfabetica).
void editar_contato(AGENDA* agenda, char* NOME);

//Percorre a lista do inicio ao fim, exibindo todos os contatos cadastrados.
void listar_contato(AGENDA* agenda);


//Retorna 1 (verdadeiro) se inicio == NULL, ou 0 (falso) caso contrario.
int agenda_vazia(AGENDA* agenda);

void agenda_libera(AGENDA* agenda);

#endif