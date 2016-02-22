#ifndef QUICKUNION_H
#define QUICKUNION_H

class QuickUnion {
public:
    QuickUnion(int n):m_count(n),size(n)
    {
        id = new int[n];
        for(int i = 0;i < n;i++){
            id[i] = i;
        }
    }
    
    ~QuickUnion()
    {
        delete [] id;
    }
    int count() { return m_count; } 
    bool connected(int p, int q) { return root(p) == root(q);}
    void uni(int p, int q);
private:
    int root(int p)
    {
        while(p != id[p]){
            p = id[p];
        }
        return p;
    }
    
    int m_count;
    int size;
    int* id;
};

void QuickUnion::uni(int p, int q)
{
    int proot= root(p);
    int qroot = root(q);

    if(proot == qroot)return;
    
    id[proot] = qroot;
    m_count--;
}
#endif
