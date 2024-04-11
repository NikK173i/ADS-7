#pragma once
// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
    SYM* next;
    SYM* prev;
};

template<typename T = SYM>
class TPQueue {
 private:
     SYM* head;
     SYM* tail;
     int cnt;

 public:
     TPQueue(): head(nullptr), tail(nullptr), cnt(0){}
     void pushback(SYM arr) {
         if (cnt == 0) {
             head= new SYM;
             head->ch = arr.ch;
             head->prior = arr.prior;
             head->next = nullptr;
             head->prev = nullptr;
             tail = head;
             cnt++;
             return;
         } else {
             SYM* tmp = tail;
             if (arr.prior > head->prior) {
                 SYM* item = new SYM;
                 item->ch = arr.ch;
                 item->prior = arr.prior;
                 item->next = nullptr;
                 item->next = head;
                 item->prev = nullptr;
                 head->prev = item;
                 head = item;
                 cnt++;
                 return;
             } else if (arr.prior <= tmp->prior) {
                 SYM* item = new SYM;
                 item->ch = arr.ch;
                 item->prior = arr.prior;
                 item->prev = nullptr;
                 item->prev = tail;
                 tail->next = item;
                 item->next = nullptr;
                 tail = item;
                 cnt++;
                 return;
             } else {
                 SYM* dead = head;
                 while (dead->next && arr.prior <= dead->prior)
                     dead = dead->next;
                 SYM* item = new SYM;
                 item->ch = arr.ch;
                 item->prior = arr.prior;
                 item->next = nullptr;
                 item->prev = nullptr;
                 item->next = dead;
                 item->prev = dead->prev;
                 dead->prev = item;
                 item->prev->next = item;
                 cnt++;
                 return;
             }
         }
     }
     SYM popup() {
         if (cnt == 0) {
             SYM arr{ '0', -1 };
             return arr;
         }
         else {
             SYM tmp;
             tmp.ch = head->ch;
             tmp.prior = head->prior;
             head = head->next;
             count--;
             return tmp;
         }
     }
};

#endif  // INCLUDE_TPQUEUE_H_
