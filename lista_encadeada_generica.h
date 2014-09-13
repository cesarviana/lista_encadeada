#ifndef LISTA_ENCADEADA_GENERICA_H_INCLUDED
#define LISTA_ENCADEADA_GENERICA_H_INCLUDED

template<typename T>
struct Element
{
    Element * next;
    T value;
};

template<typename T>
struct List
{
    int qtd;
    Element<T> * first;
};

// f(n) = 1
template<typename T>
void init( List<T> &l ){
    l.first = NULL;
    l.qtd = 0;
}
// f(n) = n-1
template<typename T>
void add( List<T> &l, T value ){
    Element<T> * elm = new Element<T>;
    elm->next = NULL;
    elm->value = value;
    if(l.first == NULL){
        l.first = elm;
    } else {
        Element<T> * nav = l.first;
        while( nav->next != NULL ){
            nav = nav->next;
        }
        nav->next = elm;
    }
    l.qtd++;
}

// f(n) = n-1
template<typename T>
void add( List<T> &l, T value, unsigned int pos ){

    if(l.qtd==0 || pos==0){
        addBegin(l, value);
    } else if(pos <= l.qtd) {
        Element<T> * elm = new Element<T>;
        elm->value = value;
        Element<T> * nav = l.first;
        int i=0;
        while( i < pos-1 ){
            nav = nav->next;
            i++;
        }
        if(pos == l.qtd)
            elm->next = NULL;
        else
            elm->next = nav->next;
        nav->next = elm;
        l.qtd++;
    }
}


// f(n) = 1
template<typename T>
void addBegin( List<T> &l, T value ){
    Element<T> * elm = new Element<T>;
    elm->value = value;
    elm->next = l.first;
    l.first = elm;
    l.qtd++;
}

// f(n) = n-1
template<typename T>
void remove(List<T> &l, int pos ){
    if(l.qtd==0 || pos < 0 || pos >= l.qtd )
        return;
    if(pos==0)
        return removeBegin(l);

    Element<T> * nav = l.first;
    int i=0;
    while( i<pos-1){
        nav=nav->next;
        i++;
    }
    Element<T> * temp = nav->next;
    if(pos==l.qtd-1)
        nav->next = NULL;
    else
        nav->next = nav->next->next;
    delete temp;
    l.qtd--;
}

// f(n) = n-1
template<typename T>
void remove( List<T> &l ){
    if( l.qtd == 0 )
        return;
    if( l.qtd == 1 ){
        delete l.first;
        l.first = NULL;
    } else {
        Element<T> * nav = l.first;
        Element<T> * aux;
        while( nav->next != NULL ){
            aux = nav;
            nav = nav->next;
        }
        aux->next = NULL;
        delete nav;
    }
    l.qtd--;
}
// f(n) = 1
template<typename T>
void removeBegin( List<T> &l ){
    if( l.qtd == 0 )
        return;
    Element<T> * temp = l.first;
    l.first = l.first->next;
    delete temp;
    l.qtd--;
}

#endif // LISTA_ENCADEADA_GENERICA_H_INCLUDED
