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

// f(n) = n/2
template<typename T>
void add( List<T> &l, T value, unsigned int pos ){
    if(pos>l.qtd)
        return;
    if(pos==0)
        return addBegin( l, value );
    if(pos==l.qtd)
        return add(l,value);

    Element<T> * elm = new Element<T>;
    elm->value = value;

    int i;
    Element<T> * nav;
    // last to first
    if( l.qtd-pos < pos ){
        nav=l.last;
        i=l.qtd-1;
        while( i > pos+1 ){
            nav=nav->prev;
            i--;
        }
        nav->prev->next = elm;
        elm->prev=nav->prev;
        elm->next=nav;
        nav->prev=elm;
    } else {
        i=0;
        nav=l.first;
        while( i < pos-1 ){
            nav=nav->next;
            i++;
        }
        nav->next->prev = elm;
        elm->next=nav->next;
        elm->prev = nav;
        nav->next=elm;
    }
    l.qtd++;
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


// f(n)=n/2
template<typename T>
void remove(List<T> &l, int pos ){
    if(l.qtd==0)
        return;
    if(pos==0)
        return removeBegin(l);
    if(pos==l.qtd-1)
        return remove(l);
    Element<T> * nav;
    Element<T> * temp;
    int i;
    if(l.qtd-pos < pos ){
        i=l.qtd-1;
        nav=l.last;
        while(i > pos+1){
            nav=nav->prev;
            i--;
        }
        temp=nav->prev;
        nav->prev=nav->prev->prev;
        nav->prev->next=nav;
    } else {
        i=0;
        nav=l.first;
        while( i < pos-1 ){
            nav=nav->next;
            i++;
        }
        temp=nav->next;
        nav->next=nav->next->next;
        nav->next->prev=nav;
    }
    delete temp;
    l.qtd--;
}
// f(n)=1
template<typename T>
void remove( List<T> &l ){
    if(l.qtd>0){
        Element<T> * temp = l.last;
        l.last = l.last->prev;
        delete temp;

        if(l.qtd==1)
            l.first = NULL;
        else
            l.last->next=NULL;

        l.qtd--;
    }
}

// f(n)=1
template<typename T>
void removeBegin( List<T> &l ){
    if(l.qtd>0){
        Element<T> * temp = l.first;
        l.first = l.first->next;
        delete temp;

        if(l.qtd==1)
            l.last = l.first;
        else
            l.first->prev=NULL;

        l.qtd--;
    }
}

#endif // LISTA_DUPLAMENTE_ENCADEADA_GENERECIA_H_INCLUDED
