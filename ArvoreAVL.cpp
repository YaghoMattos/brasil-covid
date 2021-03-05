#include "ArvoreAVL.h"


ArvoreAVL::ArvoreAVL()//construtor
{
    this->noRaiz = nullptr;//aloca raiz inicial como null
}

ArvoreAVL::~ArvoreAVL()//destrutor
{
    
}
Node* ArvoreAVL::getRaiz()//pega a raiz da arvore
{
    return this->noRaiz;//retorna a raiz da arvore
}
void ArvoreAVL::setRaiz(Node* novaRaiz)//aloca uma nova raiz passando a nova raiz como parametro
{
    this->noRaiz = novaRaiz;//a raiz recebe a nova raiz
}
Node* ArvoreAVL::buscadorDeNoPai(int valor)//busca um nó na arvore a partir do valor, retornando o nó se existir, ou o no pai caso nao exista
{
    Node* auxiliar = this->noRaiz;//começa com um no que percorre a arvore a partir do no raiz, se nao encontrar retorna o valor do nó pai
    while (auxiliar != nullptr)//enquanto esse auxiliar for diferente de null percorre a arvore
    {
        if(valor > auxiliar->getValor())//se o valor passado for maior que do auxiliar, vai para a direita
        {
            if(auxiliar->getFilhoDir() == nullptr)//se o filho a direita for null, entao o no nao existe na arvore 
            {
                return auxiliar;//e retorna o seu pai
            }
            else// se o filho nao for null
                auxiliar = auxiliar->getFilhoDir();//auxiliar pula para o filho a direita 
        }
        else if(valor < auxiliar->getValor())//se o valor for menor que o do auxiliar vai para a esquerda
        {
            if(auxiliar->getFilhoEsq() == nullptr)//se o filho a esquerda for null, entao o nó nao existe na arvore
            {
                return auxiliar;//retorna o nó pai
            }
            else // caso nao seja null o filho a esquerda
                auxiliar = auxiliar->getFilhoEsq();//auxiliar anda para a esquerda
        }
        else if(auxiliar->getValor() == valor)//caso o valor seja igual ao passado
        {
            return auxiliar;//retorna o ponteiro para este nó
        }
    }
}

bool ArvoreAVL::estahNaArvore(int valor, Node* ponteiroNo) // retorna verdadeiro ou falso se o nó esta na arvore
{
    while (ponteiroNo!=nullptr)//enquanto no passado for diferente de null
    {
    if(valor < ponteiroNo->getValor()) // compara o valor passado com o ponteiro para o no da arvore
        estahNaArvore(valor, ponteiroNo->getFilhoEsq());//se o valor passado for menor que o valor da raiz atual ele anda pra esquerda 
    else if(valor > ponteiroNo->getValor())//se o valor passado for maior que o valor da raiz apontada atualmente 
        estahNaArvore(valor, ponteiroNo->getFilhoDir());//anda pra direita
    else if(valor == ponteiroNo->getValor())//se o valor for igual
        return true;//retorna que o nó existe na raiz
    }
    //caso saia do while, é por que nao existe
    return false;//entao retorna false (nao existe este nó na arvore)
}

void ArvoreAVL::checkbalance (int valor, Node* auxiliar)// confere balanciamento
{
    while(auxiliar != nullptr)//enquanto no raiz diferente de null
    {
        if(valor < auxiliar->getValor()) //se o valor que foi passado é maior do que o valor do no
        {
            checkbalance(valor, auxiliar->getFilhoEsq());//o ponteiro anda para a esquerda
            auxiliar->atualizaFB();// depois da recursao, ele volta atualizando o fator balance
            if(!(-2<(auxiliar->getFB())<2))//se esse fator nao estiver na faixa entre -1 e 1
            {
                if((auxiliar->getFB() == 2) && (auxiliar->getFilhoDir()->getFB() == 1 || auxiliar->getFilhoDir()->getFB() == 0 ) ) //se o fb do no desbalanceado é 2 e o filho a dir é 1 
                {
                    rotacaoSimplesEsq(auxiliar);//executa rotação simples a esquerda
                }
                else if((auxiliar->getFB() == (-2)) && (auxiliar->getFilhoEsq()->getFB() == (-1) || auxiliar->getFilhoDir()->getFB() == 0 ))//se o fb do no desbalanceado é -2 e do filho a esquerda é -1
                {
                    rotacaoSimplesDir(auxiliar);//executa rotaçao simples a direita
                }
                else if( (auxiliar->getFB() == 2) && (auxiliar->getFilhoDir()->getFB() == (-1) ) )
                {
                    rotacaoDuplaEsq(auxiliar);//executa rotaçao dupla a esquerda
                }
                else if( (auxiliar->getFB() == (-2) ) && (auxiliar->getFilhoDir()->getFB() == 1 ) )
                {
                    rotacaoDuplaDir(auxiliar);//executa rotaçao dupla a direita
                }
            }
        }
        else if(valor > auxiliar->getValor())//se o valor for maior do que o atual no ponteiro
        {
            checkbalance(valor, auxiliar->getFilhoDir());//o ponteiro anda para a direita
            auxiliar->atualizaFB();// depois da recursao, ele volta atualizando o fator balance
            if(!(-2<(auxiliar->getFB())<2))//se esse fator nao estiver na faixa entre -1 e 1
            {
                if((auxiliar->getFB() == 2) && (auxiliar->getFilhoDir()->getFB() == 1 || auxiliar->getFilhoDir()->getFB() == 0 ) ) //se o fb do no desbalanceado é 2 e o filho a dir é 1 
                {
                    rotacaoSimplesEsq(auxiliar);//executa rotação simples a esquerda
                }
                else if((auxiliar->getFB() == (-2)) && (auxiliar->getFilhoEsq()->getFB() == (-1) || auxiliar->getFilhoDir()->getFB() == 0 ))//se o fb do no desbalanceado é -2 e do filho a esquerda é -1
                {
                    rotacaoSimplesDir(auxiliar);//executa rotaçao simples a direita
                }
                else if( (auxiliar->getFB() == 2) && (auxiliar->getFilhoDir()->getFB() == (-1) ) )
                {
                    rotacaoDuplaEsq(auxiliar);//executa rotaçao dupla a esquerda
                }
                else if( (auxiliar->getFB() == (-2) ) && (auxiliar->getFilhoDir()->getFB() == 1 ) )
                {
                    rotacaoDuplaDir(auxiliar);//executa rotaçao dupla a direita
                }

            }
        }
        else if(valor == auxiliar->getValor())//se o valor for igual
        {
            auxiliar->atualizaFB();//atualiza o FB do atual e volta a recursividade anterior
        }
    }

}

void ArvoreAVL::insertNode(int valor)//insere um novo nó na arvore
{
    if(estahNaArvore(valor,this->noRaiz))//se o no ja existe na arvore
    {
        cout << "o no jah existe na arvore" << endl;//printa que o no ja existe
        return;//sai da funçao
    }
    //se nao existe
    Node* no = new Node(valor);//cria um novo no dinamicamente
    if(this->noRaiz == nullptr)//se a raiz for null
        noRaiz = no;//aloca o novo no na raiz
    else//se a raiz nao for null
    {
        Node* noPai; //cria um ponteiro para o no pai
        noPai = buscadorDeNoPai(valor);//aloca o no pai no ponteiro
        if(valor < noPai->getValor())//se o valor for menor que o no pai
            noPai->setFilhoEsq(no); // ele vai ser o filho a esquerda
        else if(valor > noPai->getValor())//se o valor for maior que o no pai
            noPai->setFilhoDir(no); //ele aloca na direita
    }
    checkbalance(valor,this->noRaiz);// confere balanceamento e balanceia a arvore
    cout << "no inserido com sucesso e arvore jah balanceada" << endl;//printa o sucesso
}

void rotacaoSimplesEsq(Node* noDesbalanceado)
{
    Node* auxiliar = noDesbalanceado->getFilhoDir();// (auxiliar é o no "Q") ele é o filho a direita do no desbalanceado
    noDesbalanceado->setFilhoDir(auxiliar->getFilhoEsq()); // o no desbalanceado recebe o filho a esquerda do Q como seu filho a direita
    auxiliar->setFilhoEsq(noDesbalanceado);// o no Q passa a apontar para o no desbalanceado como filho a esquerda
    noDesbalanceado->atualizaFB();//atualiza o fb do no desbalanceado primeiro (já que é filho)
    auxiliar->atualizaFB();//atualiza Fb do no "Q" ja que é raiz
}

void rotacaoSimplesDir(Node* noDesbalanceado)
{
    Node* auxiliar = noDesbalanceado->getFilhoEsq(); // (auxiliar é o no "Q") ele é o filho a esquerda do no desbalanceado
    noDesbalanceado->setFilhoEsq(auxiliar->getFilhoDir()); // no desbalanceado passa a apontar para o filho a direita de Q como filho a esquerda
    auxiliar->setFilhoDir(noDesbalanceado);//Q passa a apontar para o no desbalanceado como seu filho a direita
    noDesbalanceado->atualizaFB();//atualiza o fb do no desbalanceado primeiro (já que é filho)
    auxiliar->atualizaFB();//atualiza Fb do no "Q" ja que é raiz
}

void rotacaoDuplaEsq(Node* noDesbalanceado) // pode ser vista como uma funçao unica
{
    Node* q = noDesbalanceado->getFilhoDir(); // no auxiliar q recebe o filho a direita do no desbalanceado
    Node* r = q->getFilhoEsq(); // no auxiliar r recebe o filho a esquerda do no auxiliar q
    noDesbalanceado->setFilhoDir(r->getFilhoEsq()); // filho a direita do no desbalanceado agora aponta para o filho a esquerda de r
    q->setFilhoEsq(r->getFilhoDir()); // filho a direita de r agora é filho a esquerda de q
    r->setFilhoEsq(noDesbalanceado); //agora com R sem filhos aponta o filho a esquerda para o no desbalanceado 
    r->setFilhoDir(q); // e o da direita para o q
    noDesbalanceado->atualizaFB(); // atualiza fb do no desbalanceado
    q->atualizaFB();// atualiza fb do no q
    r->atualizaFB(); // atualiza fb do no r
}
void rotacaoDuplaDir(Node* noDesbalanceado) // ou uma junção de duas rotaçoes simples
{  
    Node* q = noDesbalanceado->getFilhoEsq(); // no auxiliar q recebe o filho a direita do no desbalanceado
    rotacaoSimplesEsq(q);// rotaciona a esquerda
    rotacaoSimplesDir(noDesbalanceado); //depois a direita
}

