#ifndef FILA_APONTADORES_H_INCLUDED
#define FILA_APONTADORES_H_INCLUDED
#include <stdio.h>

typedef struct nodoFila *apontador;

typedef struct
{
    char chave;
    // outros
} tInfo;

struct nodoFila
{
    tInfo item;
    apontador proximo;
};

typedef struct
{
    apontador primeiro;
    apontador ultimo;
} tFila;
//---------------------------------------------
void setDados(tInfo& item);
void qInit(tFila& fila);
bool qIsEmpety(tFila& fila);
void enQueue(tFila& fila, tInfo item);
void deQueue(tFila& fila);
void print(tFila& fila);
//---------------------------------------------
enum escolhas {CRIA, ENFILEIRA, DESENFILEIRA, IMPRIME, FIM};
escolhas choice(tFila& fila);

//---------------------------------------------
escolhas choice(tFila& fila)
{
    system("cls");
    print(fila);
    int menuchoice;
    cout << "\nMenu: [FILA CIRCULAR - APONTADOR]" << endl
         << "1 - Enfileira\n"
         << "2 - Desenfileira\n"
         << "3 - Imprime\n"
         << "4 - Fim do programa\n"
         << "Opção: ";
    scanf("%d", &menuchoice);
    return (escolhas) menuchoice;
}
//---------------------------------------------
void setDados (tInfo& item)
{
    cout << "\nInforme o código: ";
    cin >> item.chave;
}
//---------------------------------------------
void qInit (tFila& fila)
{
    fila.primeiro = (apontador) malloc(sizeof(struct nodoFila));
    fila.ultimo = fila.primeiro;
    fila.primeiro->proximo = NULL;
}
//---------------------------------------------
bool qIsEmpety (tFila& fila)
{
    return fila.primeiro == fila.ultimo ? true:false;
}
//---------------------------------------------
void enQueue (tFila& fila, tInfo item)
{
    apontador p = (apontador) malloc(sizeof(struct nodoFila));
    p->item = item;
    p->proximo = NULL;
    fila.ultimo->proximo = p;
    fila.ultimo = p;
}
//---------------------------------------------
void deQueue (tFila& fila)
{
    if (qIsEmpety(fila))
    {
        cout << "ERRO: Fila vazia!\n" << endl;
    }
    else
    {
        apontador p = fila.primeiro->proximo;
        fila.primeiro->proximo = p->proximo;
        if (fila.primeiro->proximo == NULL)
            fila.ultimo = fila.primeiro;
        free(p);
    }
}
//---------------------------------------------
void print (tFila& fila)
{
    cout << "Itens na Fila: " << endl;
    if (qIsEmpety(fila))
    {
        cout << "Fila vazia." << endl;
    }
    else
    {
        apontador aux;
        aux = fila.primeiro->proximo;
        while (aux != NULL)
        {
            cout << aux->item.chave << " ";
            aux = aux->proximo;
        }
        cout << endl;
    }
}
//---------------------------------------------

#endif // FILA_APONTADORES_H_INCLUDED
