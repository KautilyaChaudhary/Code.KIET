class node{
    public:
    node *next;
    node *pre;
    int data;
    int key;
    node(int data,int key){
        this->data=data;
        this->key=key;
        next=NULL;
        pre=NULL;
    }
};
void update(node *f,node *a){
    node *t2=a->next;
    node *t3=a->pre;
    a->next=NULL;
    a->pre=NULL;
    t3->next=t2;
    t2->pre=t3;
    node *t=f->next;
    f->next=a;
    a->pre=f;
    a->next=t;
    t->pre=a;
}
void deleteN(node  *l){
    node *t=l->pre->pre;
    l->pre->next=NULL;
    l->pre->pre=NULL;
    t->next=l;
    l->pre=t;
   
}
void insert(node *f,node *a){
    node *t=f->next;
    f->next=NULL;
    t->pre=NULL;
    f->next=a;
    a->pre=f;
    a->next=t;
    t->pre=a;
}
class LRUCache {
public:
node *f=new node(-1,-1);
node *l=new node(-1,-1);
int c=0;
int s=0;
unordered_map<int,node *>vis;
    LRUCache(int cp) {
f->next=l;
l->pre=f;
     c=cp;   
    }
    
    int get(int key) {
        if(vis.find(key)!=vis.end()){
         update(f,vis[key]);
         return vis[key]->data;
        }
        return -1;
    }

    
    void put(int key, int value) {
        if(vis.find(key)!=vis.end()){
            vis[key]->data=value;
            update(f,vis[key]);
            return ;
        }
        if(s==c){
            vis.erase(l->pre->key);
            deleteN(l);
            s--;
        }
        s++;
        vis[key]=new node(value,key);
        insert(f,vis[key]);
    }
};