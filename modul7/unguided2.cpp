#include<iostream>

using namespace std;

struct antrianLL
{
    string nama;
    long long nim;
    antrianLL *next;
};

int maksimalAntrianLinkedList = 5;
antrianLL *head, *tail, *cur, *del, *newNode;

int countLinkedList(){
    if (head == NULL)
    {
        return 0;
    }else{
        int banyak = 0;
        cur = head;
        while (cur != NULL)
        {
            cur = cur-> next;
            banyak++;
        }
        return banyak;   
    }
}


//isFull linked list
bool isFullLinkedList(){
    if (countLinkedList() == maksimalAntrianLinkedList)
    {
        return true;
    }else{
        return false;
    }
}

bool isEmptyLinkedList(){
    if (countLinkedList() == 0)
    {
        return true;
    }else {
        return false;
    }
    
}

void enqueueLinkedList(string nama, long long nim){
    if (isFullLinkedList())
    {
        cout << "Antrian Penuh" << endl;
    }else{
        if (isEmptyLinkedList())
        {
            head = new antrianLL();
            head->nama = nama;
            head->nim = nim;
            head->next = NULL;
            tail = head;
        }else{
            newNode = new antrianLL();
            newNode->nama = nama;
            newNode->nim = nim;

            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }        
    }
}

void dequeueLinkedList()
{
    if (isEmptyLinkedList())
    {
        cout << "Data Antrian Kosong" <<endl;
    }else{
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}

void displayLinkedList()
{
    cout << "Data Antrian : " << endl;
    if (isEmptyLinkedList())
    {
        cout << "Data Antrian Kosong" << endl;
    }else
    {
        cout << "Banyak data antrian : " << countLinkedList() << endl;
        cur = head;
        int nomor = 1;
        while (nomor <= maksimalAntrianLinkedList)
        {
            if (cur != NULL)
            {
                cout << nomor << ". " << cur->nim << ", " << cur->nama << endl;
                cur = cur->next;
            }else
            {
                cout << nomor << ". " << "(Kosong)" << endl;
            }
            nomor++;
        }
        cout << " " << endl;
    }
    
}

void clearLinkedList()
{
    if (isEmptyLinkedList())
    {
        cout << "Data Antrian Kosong" <<endl;
    }else{
        cur = head;
        while (cur != NULL)
        {
            del = cur;
            cur = cur->next;
            del->next =  NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
        
    }   
}


int main(){
    enqueueLinkedList("Fadhil", 2311102032);
    displayLinkedList();
    enqueueLinkedList("Ilhan", 2311102029);
    enqueueLinkedList("Fani", 2311102031);
    enqueueLinkedList("Bayu", 2311102001);
    enqueueLinkedList("Somad", 2311102025);
    displayLinkedList();

    dequeueLinkedList();
    displayLinkedList();
    dequeueLinkedList();
    dequeueLinkedList();
    displayLinkedList();

    clearLinkedList();
    displayLinkedList();
}