#include "NoB.h"

NoB::NoB(int t1, bool folha1) // construtor do Nó que recebe a ordem e se é folha
{
    t = t1;
    folha = folha1;
    data = new string[2 * t - 1];
    chave = new int[2 * t - 1];
    C = new NoB *[2 * t];
    n = 0;
}

// Função que procura um  Nó, ela é um ponteiro e percorre a arvore usando a estrategia binaria
NoB *NoB::procura(int k)
{
    int i = 0;
    while (i < n && k > chave[i])
        i++;

    if (chave[i] == k)
        return this;

    if (folha == true)
        return NULL;

    return C[i]->procura(k);
}
// Função que procura uma chave especifica em um Nó, por meio do percorrimento da arvore
int NoB::achachave(int k)
{
    int idx = 0;
    while (idx < n && chave[idx] < k)
        idx++;
    return idx;
}
// Insere num vetor que tem espaço sobrando, onde ele simplismente precisa achar a posição necessaria e inserir

void NoB::inserenaocheio(int k,string d)
{
    int i = n - 1;

    if (folha == true)
    {

        while (i >= 0 && chave[i] > k)
        {

            chave[i + 1] = chave[i];
            data[i + 1] = data[i];
            i--;
        }

        chave[i + 1] = k;
        data[ i + 1] = d;
        n = n + 1;
    }
    else
    {

        while (i >= 0 && chave[i] > k)
        {
            i--;
        }

        if (C[i + 1]->n == 2 * t - 1)
        {

            dividefilho(i + 1, C[i + 1]);

            if (chave[i + 1] < k)
            {
                i++;
            }
        }
        C[i + 1]->inserenaocheio(k,d);
    }
}

// Dá o split do filho pra inserção de um novo valor, a função dá um split classico onde ele divide o filho em dois, encaixa o valor requerido e depois retorna os dois vetores e qual numero irá "subir"
void NoB::dividefilho(int i, NoB *y)
{

    NoB *z = new NoB(y->t, y->folha);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
    {
        z->chave[j] = y->chave[j + t];
        z->data[j] = y->data[j+t];
    }

    if (y->folha == false)
    {
        for (int j = 0; j < t; j++){
            z->C[j] = y->C[j + t];
        }
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
    {

        C[j + 1] = C[j];
    }

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
    {

        chave[j + 1] = chave[j];
        data[j+1] = data[j];
    }

    chave[i] = y->chave[t - 1];
    data[i] = data[t - 1];

    n = n + 1;
}
// Remove um Nó especificado, usando as duas funções auxiliares "removefolha" e "removenaofolha" permitindo que ele remova da forma mais eficiente possivel

void NoB::remove(int k)
{

    int idx = achachave(k);

    if (idx < n && chave[idx] == k)
    {

        if (folha)
            removefolha(idx);
        else
            removenaofolha(idx);
    }
    else
    {

        if (folha)
        {
            cout << "A chave " << k << " não existe na arvore\n";
            return;
        }

        bool flag = ((idx == n) ? true : false);

        if (C[idx]->n < t)
            preenche(idx);

        if (flag && idx > n)
            C[idx - 1]->remove(k);
        else
            C[idx]->remove(k);
    }
    return;
}
// Função chamada pela remove que faz uma remoção caso o Nó seja uma folha
void NoB::removefolha(int idx)
{

    for (int i = idx + 1; i < n; ++i)
    {
        chave[i - 1] = chave[i];
    }

    n--;

    return;
}
// Função chamada pela remove que faz uma remoção caso o Nó não seja uma folha, resolvendo as trocas de ponteiros e verificando se não são criadas chaves com tamanhos menores que a ordem

void NoB::removenaofolha(int idx)
{

    int k = chave[idx];

    if (C[idx]->n >= t)
    {

        int pred = getPred(idx);
        chave[idx] = pred;
        C[idx]->remove(pred);
    }

    else if (C[idx + 1]->n >= t)
    {

        int succ = getSucc(idx);
        chave[idx] = succ;
        C[idx + 1]->remove(succ);
    }

    else
    {
        juntar(idx);
        C[idx]->remove(k);
    }
    return;
}

int NoB::getPred(int idx) // Pega o predecessor
{

    NoB *cur = C[idx];

    while (!cur->folha)
        cur = cur->C[cur->n];

    return cur->chave[cur->n - 1];
}

int NoB::getSucc(int idx) // Pega o sucessor
{
    NoB *cur = C[idx + 1];

    while (!cur->folha)
        cur = cur->C[0];

    return cur->chave[0];
}

void NoB::preenche(int idx) // Função que preenche a arvore
{

    if (idx != 0 && C[idx - 1]->n >= t)
    {

        emprestaant(idx);
    }
    else if (idx != n && C[idx + 1]->n >= t)
    {
        emprestaprox(idx);
    }
    else
    {

        if (idx != n)
        {
            juntar(idx);
        }
        else
            juntar(idx - 1);
    }
    return;
}

void NoB::emprestaant(int idx) //empresta o Nó anterior
{

    NoB *filho = C[idx];
    NoB *irmao = C[idx - 1];

    for (int i = filho->n - 1; i >= 0; --i)
    {
        filho->chave[i + 1] = filho->chave[i];
    }

    if (!filho->folha)
    {
        for (int i = filho->n; i >= 0; --i)
            filho->C[i + 1] = filho->C[i];
    }

    filho->chave[0] = chave[idx - 1];

    if (!filho->folha)
        filho->C[0] = irmao->C[irmao->n];

    chave[idx - 1] = irmao->chave[irmao->n - 1];

    filho->n += 1;
    irmao->n -= 1;

    return;
}

void NoB::emprestaprox(int idx) //empresta o Nó seguinte

{

    NoB *filho = C[idx];
    NoB *irmao = C[idx + 1];

    filho->chave[(filho->n)] = chave[idx];

    if (!(filho->folha))
        filho->C[(filho->n) + 1] = irmao->C[0];

    chave[idx] = irmao->chave[0];

    for (int i = 1; i < irmao->n; ++i)
    {
        irmao->chave[i - 1] = irmao->chave[i];
    }
    if (!irmao->folha)
    {
        for (int i = 1; i <= irmao->n; ++i)
            irmao->C[i - 1] = irmao->C[i];
    }

    filho->n += 1;
    irmao->n -= 1;

    return;
}

void NoB::juntar(int idx) //Função que dá o "merge" entre dois Nós
{
    NoB *filho = C[idx];
    NoB *irmao = C[idx + 1];

    filho->chave[t - 1] = chave[idx];

    for (int i = 0; i < irmao->n; ++i)
    {
        filho->chave[i + t] = irmao->chave[i];
    }

    if (!filho->folha)
    {
        for (int i = 0; i <= irmao->n; ++i)
            filho->C[i + t] = irmao->C[i];
    }

    for (int i = idx + 1; i < n; ++i)
    {
        chave[i - 1] = chave[i];
    }

    for (int i = idx + 2; i <= n; ++i)
    {
        C[i - 1] = C[i];
    }
    filho->n += irmao->n + 1;
    n--;

    delete (irmao);
    return;
}

void NoB::percorre() // função que percorre a arvore
{

    int i;
    for (i = 0; i < n; i++)
    {

        if (folha == false)
            C[i]->percorre();
        cout << " " << chave[i];
    }
    cout << endl;

    if (folha == false)
        C[i]->percorre();
}

void NoB::percorreArquivo()
{
    Log::getInstance().iniciaArquivoSaida("Saidas/arvoreB-"+to_string(t)+".txt");
    int i;
    string line = "";
    for (i = 0; i < n; i++)
    {
        line = "";
        if (folha == false)
            C[i]->percorreArquivo();
        
        line += " " + to_string(chave[i]);
        Log::getInstance().lineArquivo(line);
    }
    

    if (folha == false)
        C[i]->percorreArquivo();
}