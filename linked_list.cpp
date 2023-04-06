#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct TNode{
    int data;
    TNode *next;
    TNode *baru;
    TNode *head;
    TNode *bantu;
    TNode *hapus;

};

void init() {
    head = NULL;
}

void insertDepan(int databaru){
	  TNode *baru;
	  baru = new TNode;
	  baru->data = databaru;
	  baru->next = NULL;
	  if(isEmpty()==1){
	 	head=baru;
	 	head->next = NULL;
	  }
	  else {
		baru->next = head;
		head = baru;
	  }
	  printf("Data masuk\n");
	} 

void insertBelakang (int databaru){
  TNode *baru,*bantu;
  baru = new TNode;
  baru->data = databaru;
  baru->next = NULL;
  if(isEmpty()==1){
    head=baru;
    head->next = NULL;
  }
  else {
    bantu=head;
    while(bantu->next!=NULL){
	 	bantu=bantu->next;
    }
    bantu->next = baru;
  }
  printf("data masuk\n");
}

void tampil(){
	TNode *bantu;
	bantu = head;
	if(isEmpty()==0){
		while(bantu!=NULL){
			cout<<bantu->data<<" ";
			bantu=bantu->next;
		}
		printf("\n");
	} else printf("Masih kosong\n");
}

void hapusDepan (){
	TNode *hapus;
	int d;
	if (isEmpty()==0){
	    if(head->next != NULL){
		    hapus = head;
		    d = hapus->data;
		    head = head->next;
		    delete hapus;
	    } else {
		    d = head->data;
		    head = NULL;
	    }
	    printf("%d terhapus\n",d);
	} else 
    cout<<"Masih kosong\n";
}

void hapusBelakang(){
	TNode *hapus,*bantu;
	int d;
	if (isEmpty()==0){
	    if(head->next != NULL){
		    bantu = head;
		    while(bantu->next->next!=NULL){		  
		        bantu = bantu->next;
		    }
		    hapus = bantu->next;
		    d = hapus->data;
      		bantu->next = NULL;
		    delete hapus;
	    } else {
		    d = head->data;
		    head = NULL;
	 }
	    printf("%d terhapus\n",d);
	} else printf("Masih kosong\n");
}

void clear(){
	TNode *bantu,*hapus;
	bantu = head;
	while(bantu!=NULL){
		hapus = bantu;
		bantu = bantu->next;
		delete hapus;
	}
	head = NULL;	
}

int main() {
    
}


