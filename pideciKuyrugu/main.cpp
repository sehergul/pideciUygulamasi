#include <iostream>
#define PIDE 3
#define SIZE 10


using namespace std;

struct node{
    string ad;
    int data, pideSayisi, ucret;
    node* next;
};

struct queue{
    int indis=0;
    node *front=NULL, *rear=NULL;
};

void enqueue(queue *q, string ad, int pideSayisi){
    node *musteri= new node();
    musteri->ad=ad;
    musteri->pideSayisi=pideSayisi;
    musteri->ucret=pideSayisi*PIDE;

    if(q->indis==SIZE){ cout << "Pide kuyrugu dolu!" << endl;}

    else if(q->indis==0){ //kuyruk bos ise
        musteri->next=NULL;
        q->rear=q->front=musteri;
        q->indis++;
        cout << ad << " kuyruga girdi ve kuyruk olusturuldu!" << endl;}
    else{
        musteri->next=q->rear;
        q->rear=musteri;
        q->indis++;
        cout << ad << " kuyruga girdi!" << endl;}
}


void dequeue(queue *q){
    if(q->indis==0) {cout << "Kuyruk bos!" << endl;}
    else if(q->indis==1){
        cout << q->front->ad << ", " << q->front->pideSayisi << " pideye " << q->front->ucret << " TL odeyip kuyruktan cikti!" << endl;
        cout << "Pide kuyrugu kalmadi!" << endl;
        delete q->front;
        q->rear=q->front=NULL;
        q->indis--;
    }
    else{
        node *iter=q->rear;
        while(iter->next!=q->front)
            iter= iter->next;
        cout << q->front->ad << ", " << q->front->pideSayisi << " tane pide alarak " << q->front->ucret << " TL odeyip kuyruktan cikti!" << endl;
        delete q->front;
        q->front = iter;
        q->front->next=NULL;
        q->indis--;

    }
}

void print(queue *q){
    if(q->indis==0) {cout << "Kuyruk bos!" << endl;}
    else{
        node *iter= q->rear;
        while(iter!=NULL){
            cout << iter->ad << ", " << iter->pideSayisi << " pide, " << iter->ucret << " TL" << endl;
            iter=iter->next;}
    }
}


int main()
{
    queue qu;
    int pideSayisi, secim;
    string ad;

    while(true){
        cout << endl;
        cout << "PIDE KUYRUGU" << endl;
        cout << "1- Kuyruga gir " << endl;
        cout << "2- Kuyruktan cik " << endl;
        cout << "3- Kuyruktakilerin listesi " << endl;
        cout << "4- Cikis " << endl;
        cout << "Yapmak istediginiz islemi seciniz: "; cin >> secim;
        switch(secim){
        case 1:
            cout << "Ad: "; cin >> ad;
            cout << "Pide sayisi: "; cin >> pideSayisi;
            enqueue(&qu, ad, pideSayisi);
            break;
        case 2:
            dequeue(&qu);
            break;
        case 3:
            print(&qu);
            break;
        case 4:
            cout << "Cikis yapiliyor..." << endl;
            return 0;
        default:
            cout << "Lutfen gecerli bir islem giriniz!" << endl;
            break;
        }
    }
    return 0;
}
