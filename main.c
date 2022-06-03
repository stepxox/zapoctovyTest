#include <stdio.h>
#include <stdlib.h>

/*
 *
    Vytvořte jednostranný Linked list () naplňte jej pomocí funkce insert() - nutné
    využití malloc - nezapomeňte na free - tato funkce vloží novou hlavičku a vrátí celý nový list s touto novou hlavičkou. Následně implementujete následující funkce:

    Za známku "C":
    Vytvořte funkci someEven pomocí REKURZE -Array.prototype.some() - JavaScript | MDN (mozilla.org) která vrátí 1, pokud nějaké
    číslo v předaném LL je sudé. Pak jej vypište klasickým způsobem.
    Input: 4->3->2->1->NULL
    Output: 1 (true)

    Po dokončení všech funkcí demonstrujte ukázku učiteli.

    Za známku "A":

    Vytvořte funkci filterEvenOdd pomocí REKURZE - která vrátí novou strukturu EvenOdd (viz tabule), která bude
    obsahovat ukazatele na linked list sudých hodnot předaného LL a ukazatele na linked list lichých hodnot předaného LL. Pak jej vypište klasickým způsobem.
    Input: 4->3->2->1->NULL
    Output:
    EvenOdd.even : 4-2->NULL
    EvenOdd.odd : 3-1->NULL
 */

// vytvoreni struktury linked listu
typedef struct List {
    int data;
    struct List *next;
} List;

/*typedef struct EvenOdd{
    int data;
    //struct List *next;
    struct List *even;
    struct List *odd;
}EvenOdd;*/

struct List *insert(struct List *old, int n) {
    struct List *list = malloc(
            sizeof(struct List)); //vytvoreni noveho prazdneho linked listu, nastaveni dat a nasledujiciho listu, pak ho vratim
    list->data = n;
    list->next = old;
    return list;
}
// someEven bez rekurze
/*int someEven(struct List *list){
    struct List* current = list;
    while(current != NULL){
        if(current->data %2 == 0) return 1;
        current = current->next;
    }
};*/

//someEven rekurzivne
int someEvenR(struct List *list) {
    if (list->data % 2 == 0) return 1; // jestli je delitelny 2 bez zbytku = return 1
    if (list->next == NULL) return 0; // neni zadne sude (vsechny jsou liche) cislo = return 0
    return someEvenR(list->next); // start rekurze
}

// filterEvenOdd rekurzivne
/*int filterEvenOdd(struct List *list){
    if(list->data %2 == 0) printf("\nEvenOdd.even:%d", list->data);
    else printf("\nEvenOdd.odd:%d", list->data);
    return filterEvenOdd(list->next);
}*/

// vypsani linked listu // test
/*void print(struct List *list){
    //struct List* current = list;
    while(list != NULL){
        printf("\ntest%d", list->data);
        list = list->next;
    }
}*/

void freeLinkedList(List* start)
{
    List* current;
    while (start != NULL){
        current = start;
        start = start->next;
        free(current);
    }
}

int main() {
    struct List *start = malloc(sizeof(struct List)); // Vytvoreni noveho linked listu
    start->data = 1; //4->3->2->1->NULL // Nastavime data do nove vytvoreneho linked listu
    start->next = NULL;
    struct List *end;
    end = insert(start, 2); // Pridame doleva 2, 3, 4
    end = insert(end, 3);
    end = insert(end, 4);
    int out = someEvenR(
            end); // Zkontrolujeme jestli linked list ma nejake sude cislo, pokud ano, vypiseme 1, pokud ne, tak 0
    printf("%d", out); // Vypsani 1 nebo 0 (podle podminek funkce)
    //print(end); // Vypsani linked listu // test
    //filterEvenOdd(end);
    freeLinkedList(start); // Uvolneni pameti

    return 0;
}
