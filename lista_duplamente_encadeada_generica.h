#ifndef LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED
#define LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED

template<typename T>
struct Element{
    Element<T> * next;
    Element<T> * prev;
    T value;
};

template<typename T>
struct List{
    Element<T> * first;
    Element<T> * last;
    int qtd;
};

// f(n) = 1
template<typename T>
void init( List<T> &l ){
    l.first = NULL;
    l.last  = NULL;
    l.qtd = 0;
}

// f(n) = 1
template<typename T>
void add( List<T> &l, T value ){
    Element<T> * elm = new Element<T>;
    elm->value = value;
    elm->next = NULL;
    if(l.qtd==0){
        elm->prev=NULL;
        l.first=elm;
    }else{
        elm->prev=l.last;
        l.last->next=elm;
    }
    l.last=elm;
    l.qtd++;
}

// f(n) = ????
template<typename T>
void add( List<T> &l, T value, unsigned int pos ){

}

// f(n) = 1
template<typename T>
void addBegin( List<T> &l, T value ){
    Element<T> * elm = new Element<T>;
    elm->value = value;
    elm->prev = NULL;
    if(l.qtd==0){
        elm->next=NULL;
        l.last=elm;
    }else{
        elm->next=l.first;
        l.first->prev=elm;
    }
    l.first=elm;
    l.qtd++;
}

#endif // LISTA_DUPLAMENTE_ENCADEADA_GENERECIA_H_INCLUDED
