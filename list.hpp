#ifndef TWO_WAY_HEAD
#define TWO_WAY_HEAD
#include <vector>

/**
    Two-way headed iterator linked list
**/

template <typename Item>
class List{
private:
    Item* key;
    List* next;
    List* prev;
    List(Item* a) : key(a), next(nullptr), prev(nullptr) {}
    void delAll();
public:
    List() : next(this), prev(this) {}
    List(std::vector<Item> t);   ///Build list from vector
    List* Next() {return next;}
    List* Prev() {return prev;}
    Item* Key() {return key;}
    List* find(Item wh);
    void InsBack(Item* ins);    ///Insert the elem to back of list
    void InsFront(Item* ins);   //Insert the elem to front of list
    void InsBef(Item* ins, Item wh);    /// Insert elem (ins) before (wh)
    void InsBef(Item* ins);             // Insert elem (ins) before actual
    void InsBef(List* ins) {InsBef(ins->Key());}
    void InsAft(Item wh, Item* ins);    ///Insert elem (ins) after wh
    void InsAft(Item* ins);     //Insert elem (ins) after actual
    void InsAft(List* ins) {InsAft(ins->Key());}
    void Rem(Item wh);      //Remove wh from list if contains
    void Rem();     ///Remove actual elem
    void Display();     // Write whole list to standard output
    int length();
    void concat(List<Item>* q); ///Concatenate the whole list with another list (q)
    ~List() {delAll();}
};

template<typename Item>
List<Item>::List(std::vector<Item> t){
    List<Item>* p = this;
    for(int i=0;i<t.size();i++){
          List<Item>* lins = new List(t[i]);
          p->next = lins;
          lins->prev = p;
          p = p->next;
        }
}

template<typename Item>
List<Item>* List<Item>::find(Item wh){
    List<Item>* p = this->next;
    while(p != this && p->key != wh) p = p->next;
    return (p->key == wh) ? p : nullptr;
}

template<typename Item>
void List<Item>::InsBack(Item* ins){
    List<Item>* p = this;
    List<Item>* lins = new List(ins);
    lins->next = p;
    lins->prev = p->prev;
    p->prev->next = lins;
    p->prev = lins;
}

template<typename Item>
void List<Item>::InsFront(Item* ins){
    List<Item>* p = this;
    List<Item>* lins = new List(ins);
    lins->prev = p;
    lins->next = p->next;
    p->next->prev = lins;
    p->next = lins;
}

template<typename Item>
void List<Item>::InsBef(Item* ins, Item wh){
    List<Item>* lins = new List(ins);
    List<Item>* q = find(wh);
    lins->next = q;
    lins->prev = q->prev;
    q->prev->next = lins;
    q->prev = lins;
}

template<typename Item>
void List<Item>::InsBef(Item* ins){
    List<Item>* lins = new List(ins);
    List<Item>* q = this;
    lins->next = q;
    lins->prev = q->prev;
    q->prev->next = lins;
    q->prev = lins;
}

template<typename Item>
void List<Item>::InsAft(Item wh, Item* ins){
    List<Item>* lins = new List(ins);
    List<Item>* q = find(wh);
    lins->prev = q;
    lins->next = q->next;
    q->next->prev = lins;
    q->next = lins;
}

template <typename Item>
void List<Item>::InsAft(Item* ins) {
    List<Item>* lins = new List(ins);
    List<Item>* q = this;
    lins->prev = q;
    lins->next = q->next;
    q->next->prev = lins;
    q->next = lins;
}

template<typename Item>
void List<Item>::Rem(Item wh){
    List<Item>* q = find(wh);
    q->prev->next = q->next;
    q->next->prev = q->prev;
    free(q);
}

template<typename Item>
void List<Item>::Rem(){
    List<Item>* p = this;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

template<typename Item>
void List<Item>::delAll(){
    List<Item>* p = this->next;
    while(p!=this){
        p = p->next;
        free(p->prev);
    }
    p->next = p->prev = p;
}

template<typename Item>
void List<Item>::Display(){
    List<Item>* p = this->next;
    if(p->next == p->prev){
        std::cout << "Empty list";
    }
    else {
    while(p != this) {
        std::cout << p->key << "  ";
        p = p->next;
        }
    }
    std::cout << std::endl;
}

template<typename Item>
int List<Item>::length(){
int k=0;
List<Item>* p = this->next;
while(p != this){
    k++;
    p = p->next;
    }
return k;
}

template<typename Item>
void List<Item>::concat(List<Item>* q){
    List<Item>* p = this;
    p->prev->next = q->next;
    q->next->prev = p->prev;
    q->prev->next = p;
    p->prev = q->prev;
    delete q;
}



#endif
