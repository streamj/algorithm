#ifndef WQUICKUNION_H
#define WQUICKUNION_H

class WeightedQuickUnion {
public:
    WeightedQuickUnion(int n):m_count(n),size(n)
    {
        id = new int[n];
        for(int i = 0;i < n;i++){
            id[i] = i;
        }
        sz = new int[n];
        for(int i = 0; i< n;i++){
            sz[i] = 1;
        }
    }
    
    ~WeightedQuickUnion()
    {
        delete [] sz;
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
    int* sz;
};

void WeightedQuickUnion::uni(int p, int q)
{
    int i= root(p);
    int j = root(q);

    if(i == j)return;
   
    if(sz[i] < sz[j]){
        id[i] = j;
        sz[j] += sz[i];
    }else{
        id[j] = i;
        sz[i] += sz[j];
    }
    m_count--;
}
#endif
