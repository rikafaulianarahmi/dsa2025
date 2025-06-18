#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        cout << "Data bertambah";
    } else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    } else {
        cout << "Data sudah ada";
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->kiri);
        freeTree(root->kanan);
        delete root;
    }
}

int main() {
    int pil, data;
    Node *pohon = NULL;

    do {
        system("cls");
        cout << "==========================\n";
        cout << "   PROGRAM BINARY TREE\n";
        cout << "==========================\n";
        cout << "1. Tambah\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "==========================\n";
        cout << "Pilihan : ";
        cin >> pil;

        switch (pil) {
            case 1:
                cout << "INPUT :";
                cout << "\n------------------------\n";
                cout << "Data baru   : ";
                cin >> data;
                tambah(&pohon, data);
                break;

            case 2:
                cout << "PreOrder";
                cout << "\n------------------------\n";
                if (pohon != NULL) {
                    preOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                break;

            case 3:
                cout << "InOrder";
                cout << "\n------------------------\n";
                if (pohon != NULL) {
                    inOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                break;

            case 4:
                cout << "PostOrder";
                cout << "\n------------------------\n";
                if (pohon != NULL) {
                    postOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                break;

            case 5:
                freeTree(pohon);  
                cout << "\nTree berhasil dibersihkan. Keluar program.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }

        cout << "\n\nTekan sembarang tombol untuk melanjutkan...";
        _getch();

    } while (pil != 5);

    return EXIT_FAILURE; 
}