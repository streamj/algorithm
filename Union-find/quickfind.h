#ifndef QUICKFIND_H
#define QUICKFIND_H

class QuickFind {
public:
    QuickFind(int n):m_count(n),size(n)
    {
        id = new int[n];
        for(int i = 0;i < n;i++){
            id[i] = i;
        }
    }
    
    ~QuickFind()
    {
        delete [] id;
    }
    int count() { return m_count; } 
    bool connected(int p, int q) { return find(p) == find(q);}
    void uni(int p, int q);
private:
    int find(int p) { return id[p];}
    
    int m_count;
    int size;
    int* id;
};

void QuickFind::uni(int p, int q)
{
    int pid = find(p);
    int qid = find(q);

    if(pid == qid)return;

    for(int i = 0; i < size; i++){
        if(id[i] == pid){
            id[i] = qid;
        }
    }
    m_count--;
}
#endif
