#include <iostream>

using namespace std;

struct Tnode {
    int data1;
    int data2;
    Tnode *next;
};

Tnode *head;
Tnode *tail;
Tnode *curr;
Tnode *entry;
Tnode *del;
Tnode *result;
void inisialisasiTnode() {
    head = NULL;
    tail = NULL;
}
void inputData(int data2) {
    entry = (Tnode*)malloc(sizeof(Tnode)); //alokasi memori
    entry->data1 = data2;
    entry->next = NULL;
    if(head == NULL) {
        head = entry;
        tail = head;
    } else {
        tail->next = entry;
        tail = entry;
    }
}

void updateTnode(int data2, int entry) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    curr = head;
    for (int i = 0; i < entry; i++) {
        if(curr == NULL) {
            cout << "Index sudah mencapai batas" << endl;
            return;
        }
        curr = curr->next;
    }
    curr -> data1 = data2;
}

void hapus(int value) {
    int simpan;
    curr = head;
    Tnode *previous = NULL;

    // Traverse linked list hingga menemukan node dengan nilai yang dicari
    while (curr != NULL && curr->data1 != value) {
        previous = curr;
        curr = curr->next;
    }

    // Jika node dengan nilai yang dicari ditemukan
    if (curr != NULL) {
        // Jika node yang ingin dihapus adalah head
        if (curr == head) {
            head = head->next;
        } else {
            // Menghapus node dengan mengubah pointer next dari previous node
            previous->next = curr->next;
        }

        // Hapus node dari memory
        delete curr;
        curr = NULL;
    }
}

void cetakTnode() {
    curr = head;
    if (head == NULL) {
        cout << "\n linked list is empty" << endl;
    } else {
        cout << "\nData yang ada di dalam linked list adalah" << endl;
        while(curr != NULL) {
            cout << curr -> data1 << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl << endl << endl << endl;
    }
}

Tnode *searchLinkedList(int value) {
    curr = head;

    // Traverse linked list hingga menemukan node dengan nilai yang dicari
    while (curr != NULL) {
        if (curr->data1 == value) {
            return curr; // Mengembalikan pointer ke node dengan nilai yang dicari
        }
        curr = curr->next;
    }

    return NULL; // Tnode dengan nilai yang dicari tidak ditemukan
}

void insertTnode(Tnode* &head, int value, int position) {
    Tnode* newTnode = new Tnode;
    newTnode->data1 = value;

    Tnode* current = head;
    int currentPosition = 0;

    // Traverse linked list hingga mencapai posisi yang diinginkan
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // Jika posisi yang diinginkan tidak ditemukan, keluar dari function
    if (current == NULL) {
        cout << "Posisi yang diinginkan tidak valid" << endl;
        return;
    }

    // Menyisipkan node baru di antara node sebelum dan node setelah
    newTnode->next = current->next;
    current->next = newTnode;
}

void menu() {
    bool i = true;
    int pilihan;
    int data1, data2, entry, value;

    while(i) {
        cout << "=====================================" << endl;
        cout << "Single Linked List Non-Circular" << endl;
        cout << "=====================================" << endl;
        cout << "Menu : " << endl;
        cout << "1. Menambah Data " << endl;
        cout << "2. Melihat Data " << endl;
        cout << "3. Menghapus Data" << endl;
        cout << "4. Update Data " << endl;
        cout << "5. Mencari Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Masukkan pilihan kamu : " ;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Data : ";
                cin >> data1;
                inputData(data1);
                break;
            case 2:
                cetakTnode();
                break;
            case 3:
                cout << "masukkan data yang ingin dihapus : " ;
                cin >> value;
                hapus(value);
                break;
            case 4:
                cout << "Masukkan data baru : ";
                cin >> data2;
                cout << "Pilih Index : " ;
                cin >> entry;
                updateTnode(data2, entry);
                break;
            case 5:
                cout << "Masukkan data yang akan dicari : ";
                cin >> value;
                result = searchLinkedList(value);
                if (result == NULL) {
                    cout << "\nData " << value << " Tidak ada di dalam linked list" << endl << endl;
                } else {
                    cout << "\nData " << value << " ditemukan di alamat memori " << result << endl << endl;
                }
                break;
            case 6:
                i = false;
                break;
            case 7:
                cout << "masukkan sebuah value : ";
                cin >> value;
                cout << "masukkan sebuah posisi node : ";
                int position;
                cin >> position;
                insertTnode(head, value, position);
                break;
            default: 
                cout << "Tidak ada pilihan tersebut !!" << endl;
                break;
        }
        
    }
    cout << "Terima kasih sudah menggunakan kode kami";
}

int main() {
    inisialisasiTnode();
    menu();
}