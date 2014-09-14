#include <iostream>
#include <conio2.h>

#include "lista_duplamente_encadeada_generica.h"
//#include "lista_encadeada_generica.h"
using namespace std;

template<typename T>
void printList( List<T> &l ){
    Element<T> * nav = l.first;
    cout << "qtd = " << l.qtd << endl;
    while( nav != NULL ){
        cout << nav->value << ", ";
        nav=nav->next;
    }
    cout << endl;
}

int main()
{
    List<int> l;
    init(l);
    //add(l, 0);
    //add(l, 1);
    //printList(l);
    add( l, 0, 0 );
    add( l, 1, 1 );
    add( l, 2, 2 );
    add( l, 3, 3 );
    add( l, 7, 2 );
    add( l, 7, 2 );
    printList(l);
    remove( l );
    remove( l );
    remove( l );
    printList(l);
    /*removeBegin(l);
    remove(l);
    addBegin(l, 2);
    addBegin(l, 3);
    add( l, 7, 1 );
    add( l, 9, 4 );
    remove( l, 1 );
    remove( l, 0 );*/

	return 0;
}

