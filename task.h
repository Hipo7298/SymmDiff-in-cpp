#ifndef TASK_H
#define TASK_H
#include "list.hpp"
#include <fstream>

void Fill(List<int>* f, std::string k){
std::fstream file;
file.open(k);
int num;
while(file >> num) f->InsFront(&num);
file.close();
}

void symdiff(List<int>* a, List<int>* b){
 List<int>* p = a->Next();
 List<int>* q = b->Next();

    while(p != a && q != b){
        if(q->Key() < p->Key()){
            p->InsBef(q);
            q = q->Next();
            q->Prev()->Rem();
        }
        else if(p->Key() < q->Key()) p = p->Next();
        else /*if(p->key == q->key)*/{
            p = p->Next();
            q = q->Next();
            p->Prev()->Rem();
            q->Prev()->Rem();
            }
        }

    if(p == a) p->concat(q);
    free(q);
}

#endif // TASK_H
