struct tdatum{
       int dan,mjesec,godina;
       };

struct elem {
       char pre_ime[35];
       tdatum datum;
       float tekuci,devizni;
       int a,b,c,d;
       };
       
struct qu {
       elem klijent;
       qu *sljedeci;
       };
       
struct que {
       qu *front,*rear;
       };
       
que q,salter,brzi,novi;
int n,placanje=0;
typedef que& red;

elem FrontQ(que& q) {
     if(q.front==q.rear) exit(0);
     return (q.front->sljedeci)->klijent;
     }
     
void EnQueueQ(elem x,que& q) {
     qu *zadnji = q.front,*novi;
     while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
     novi = new qu;
     novi->sljedeci=NULL;
     novi->klijent=x;
     zadnji->sljedeci=novi;
     q.rear=novi;
     }
     
void DeQueueQ(que& q) {
     if(q.front==q.rear) return;
     qu *brisi = q.front;
     q.front=brisi->sljedeci;
     delete brisi;
     }

bool IsEmptyQ(que& q) {
     if(q.front==q.rear) return true;
     else return false;
     }
     
void InitQ(que& q) {
     qu* novi = new qu;
     novi->sljedeci=NULL;
     q.rear=novi;
     q.front=novi;
     } 
