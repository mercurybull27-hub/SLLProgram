#include <iostream>

struct ElmList {
    int info;
    ElmList* next;
};

struct List {
    ElmList* first;
};

void createList(List& L) {
    L.first = nullptr;
}

ElmList* createNewElement(int val) {
    return new ElmList{val, nullptr};
}

void insertFirst(List& L, ElmList* P) {
    if (!P) return;
    P->next = L.first;
    L.first = P;
}

void insertLast(List& L, ElmList* P) {
    if (!P) return;
    if (!L.first) {
        L.first = P;
        return;
    }
    ElmList* curr = L.first;
    while (curr->next) curr = curr->next;
    curr->next = P;
}

void insertAfter(List& L, ElmList* Prec, ElmList* P) {
    if (Prec && P) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printList(List L) {
    for (ElmList* p = L.first; p; p = p->next) {
        std::cout << p->info << " ";
    }
    std::cout << "\n";
}

ElmList* searchElement(List L, int key) {
    for (ElmList* p = L.first; p; p = p->next) {
        if (p->info == key) return p;
    }
    return nullptr;
}

void deleteFirst(List& L) {
    if (!L.first) return;
    ElmList* temp = L.first;
    L.first = L.first->next;
    delete temp;
}

int main() {
    List L;
    createList(L);

    insertLast(L, createNewElement(10));
    insertLast(L, createNewElement(20));
    insertLast(L, createNewElement(30));

    std::cout << "print          -> ";
    printList(L);

    // Menggunakan insertFirst untuk memasukkan angka 5 ke posisi paling depan
    insertFirst(L, createNewElement(5));

    std::cout << "print          -> ";
    printList(L);

    std::cout << "search 20      -> " << (searchElement(L, 20) ? "FOUND" : "NOT FOUND") << "\n";

    deleteFirst(L);

    std::cout << "print          -> ";
    printList(L);

    return 0;
}