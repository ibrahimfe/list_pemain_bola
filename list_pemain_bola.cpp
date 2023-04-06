#include <iostream> 
#include <cstdlib> //Library untuk fungsi 
#include <string>

using namespace std;

// Membuat struktur data Node pada linked list yang berisi detail Pemain Bola
struct Node {
    string negaraPemain;    //atribut negara pemain Bola dari Node
    string klubPemain;      //atribut klub Pemain bola dari Node
    string posisiPemain;    //atribut posisi Pemain Bola dari Node
    string namaPemain;      //atribut nama Pemain Bola dari Node
    int backNmbrPemain;     //atribut nomor punggung pemain bola dari Node

    //pointer ke node berikutnya
    Node* next;
};

//Function untuk meninputkan data pada node baru
void input_data(Node** head, string negaraPemain, string klubPemain, string posisiPemain, string namaPemain, int backNmbrPemain) {
    //membuat node baru untuk alokasi memori struktur data Node()
    Node* newNode = new Node();

    //memasukkan data ke dalam node
    newNode->negaraPemain = negaraPemain;
    newNode->klubPemain = klubPemain;
    newNode->posisiPemain = posisiPemain;
    newNode->namaPemain = namaPemain;
    newNode->backNmbrPemain = backNmbrPemain;

    //memasukkan pointer next kedalam newNode
    newNode->next = NULL;

    //mengecek apakah node head kosong atau tidak
    if(*head == NULL) {
        *head = newNode;    //head kosong maka data newNode dimasukkan ke dalam node Head
    } else {
        Node* currentNode = *head; //node head TIDAK kosong, maka node head dipindahkan ke currentNode

        //memasukkan pointer next kedalam node ketika pointer NULL maka loop selesai
        while(currentNode->next != NULL) { 
            currentNode = currentNode->next;    
        }
        currentNode->next = newNode;
    }

}

// Function untuk menampilkan data pada linked list
void menampilkan_Data(Node* head) {
    if (head == NULL) {
        cout << "Tidak ada yang dapat ditampilkan !!" << endl;
        cout << "Data masih Kosong" << endl;
    } else {
        //memasukkan data pada node head kedalam pointer currentNode
        Node* currentNode = head;

        short i = 1;

        //loop akan bernilai TRUE ketika masih ada data di dalam node
            while (currentNode != NULL) {
            cout << "===============================================================" << endl;
            cout << "Data ke-" << i << endl;
            cout << "Pemain bola berasal dari negara : " << currentNode->negaraPemain << endl;
            cout << "Pemain bola berasal dari klub : " << currentNode->klubPemain << endl;
            cout << "Posisi Pemain di lapangan : " << currentNode->posisiPemain << endl;
            cout << "nama pemain : " << currentNode->namaPemain << endl;
            cout << "nomor punggung pemain : " << currentNode->backNmbrPemain << endl;
            cout << "===============================================================" << endl;

            //memindahkan node ke node selanjutnya
            currentNode = currentNode->next;
            i++;
        }
        
    }
}

//Function untuk menampilkan Menu
int welcome_screen() {
    int x;

    cout << "===============================================================" << endl;
    cout << "List Pemain Bola" << endl;
    cout << "Kamu bisa menginput dan menampilkan list pemain bola yang ada!!" << endl;
    cout << "===============================================================" << endl;
    cout << "Apa yang ingin kamu lakukan ?" << endl;
    cout << "1. Input Pemain Bola" << endl;
    cout << "2. Tampilkan daftar Pemain Bola" << endl;
    cout << "3. Keluar dari Program " << endl;
    cout << "Input : ";
    
    cin >> x;
    return x;
}

//Function untuk membersihkan terminal
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Untuk sistem operasi Windows
    #else
        system("clear"); // Untuk sistem operasi Unix
    #endif
}


int main() {
    //inisialisasi node head sebagai NULL
    Node* head = NULL;
    
    /*Deklarasi variabel untuk memasukkan atribut atribut di dalam node*/
    string negara_pemain, klub_pemain, posisi_pemain, nama_pemain;
    short nomorpunggung;

    short x = 0;

    while(x != 3) {
        x = welcome_screen();
        switch (x)
        {
            //input Data
        case 1:
            clearScreen();
            cin.ignore();
            cout <<  "Masukkan negara pemain : "; getline(cin, negara_pemain);
            cout <<  "Masukkan Klub pemain bermain : "; getline(cin, klub_pemain);
            cout <<  "Masukkan Posisi pemain di lapangan : "; getline(cin, posisi_pemain);
            cout <<  "Masukkan Nama pemain : "; getline(cin, nama_pemain);
            cout <<  "Masukkan Nomor Punggung pemain : "; cin >> nomorpunggung;
            input_data(&head, negara_pemain, klub_pemain, posisi_pemain, nama_pemain, nomorpunggung);
            break;

            //Menampilkan Data
        case 2:
            clearScreen();
            menampilkan_Data(head);
            break;

        //Keluar Dari Program
        case 3:
            clearScreen();
            cout << "Terima kasih sudah menggunakan program saya !!" << endl;
            break;

        //User memilih selain pilihan yang ada
        default:
            cout << "Tidak ada pilihan tesebut di dalam program !!" << endl;
            break;
    }   
    
    }
    

}