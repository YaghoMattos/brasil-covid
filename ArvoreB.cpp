#include "ArvoreB.h"

ArvoreB::ArvoreB(int _t) //construtor arvore
{
    raiz = NULL;
    t = _t;
}
// função que percorre a arvore chamando a função equivalente no Nó, começando pela raiz

void ArvoreB::percorre()
{
    if (raiz != NULL)
        raiz->percorre();
}
// função que procura um Nó arvore chamando a função equivalente no Nó

NoB *ArvoreB::procura(int k)
{
    return (raiz == NULL) ? NULL : raiz->procura(k);
}
// Função que insere na arvore usando os metodos "inserenaocheio" e "dividefilho", implementadas no Nó

void ArvoreB::insert(int k)
{

    if (raiz == NULL)
    {

        raiz = new NoB(t, true);
        raiz->chave[0] = k;
        raiz->n = 1;
    }
    else
    {
        if (raiz->n == 2 * t - 1)
        {
            NoB *s = new NoB(t, false);

            s->C[0] = raiz;

            s->dividefilho(0, raiz);

            int i = 0;
            if (s->chave[0] < k)
            {

                i++;
            }
            s->C[i]->inserenaocheio(k);

            raiz = s;
        }
        else
        {
            raiz->inserenaocheio(k);
        }
    }
}
// Função que remove um Nó passado, utiliza a função "remove" implementada no Nó.

void ArvoreB::remove(int k)
{
    if (!raiz)
    {
        cout << "A arvore está vazia\n";
        return;
    }

    raiz->remove(k);

    if (raiz->n == 0)
    {

        NoB *tmp = raiz;
        if (raiz->folha)
            raiz = NULL;
        else
        {
            raiz = raiz->C[0];
        }
        delete tmp;
    }
    return;
}

void ArvoreB::imprimir()
{
    NoB *p = raiz;
    p->percorre();
}

void ArvoreB::imprimirArquivo()
{
    NoB *p = raiz;
    p->percorreArquivo();
}