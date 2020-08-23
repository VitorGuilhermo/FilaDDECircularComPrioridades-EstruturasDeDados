struct TpFilaDDECircularPrioridade{
    char elemento;
    int prioridade;
    TpFilaDDECircularPrioridade *ant, *prox;
};
struct TpDescritor{
    TpFilaDDECircularPrioridade *inicio, *fim;
};

void inicializar(TpDescritor &desc){
    desc.inicio = desc.fim = NULL;
}

TpFilaDDECircularPrioridade *novaCaixa(char elemento, int prioridade){
    TpFilaDDECircularPrioridade *caixa = new TpFilaDDECircularPrioridade;

    caixa->elemento = elemento;
    caixa->prioridade = prioridade;
    caixa->prox = NULL;
    caixa->ant = NULL;
    return caixa;
}
void inserir(TpDescritor &desc, char elemento, int prioridade){
    TpFilaDDECircularPrioridade *nc, *aux;

    nc = novaCaixa(elemento, prioridade);

    if(desc.inicio == NULL)
        desc.inicio = desc.fim = nc;
    else{
        if(prioridade < desc.inicio->prioridade){   //insere no inicio
            nc->prox = desc.inicio;
            nc->ant = desc.fim;
            desc.inicio = nc;
            desc.fim->prox = desc.inicio;
        }
        else if(prioridade >= desc.fim->prioridade){ //insere no fim
            nc->ant = desc.fim;
            nc->prox = desc.inicio;
            desc.fim->prox = nc;
            desc.fim = nc;
        }
        else{
            aux = desc.inicio;
            while(aux->prox != NULL && aux->prox != desc.inicio && prioridade >= aux->prox->prioridade)
                aux = aux->prox;

            nc->ant = aux;
            nc->prox = aux->prox;
            aux->prox->ant = nc;
            aux->prox = nc;

            //if(aux->prox == NULL)
              //  desc.fim = aux;
        }
    }

}

void retirar(TpDescritor &desc){
    TpFilaDDECircularPrioridade *aux;

    if(desc.inicio != NULL){
        aux = desc.inicio;
        desc.inicio = desc.inicio->prox;
        desc.inicio->ant = desc.fim;
        desc.fim->prox = desc.inicio;
        delete(aux);
    }
}

void exibir(TpDescritor &desc){
    TpFilaDDECircularPrioridade *aux;

    aux = desc.inicio;
    while(aux != NULL && aux->prox != desc.inicio){
        printf("\t%c - %d", aux->elemento, aux->prioridade);
        aux = aux->prox;
    }
    printf("\t%c - %d", aux->elemento, aux->prioridade);
}









