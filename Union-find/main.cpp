#include <stdio.h>
#include <stdlib.h>
#include "wquickunion.h"

int main(int argc, char** argv)
{
    if(argc != 2) {
        printf("need the finename\n");
        exit(1);
    }
    char* filename = argv[1];
    FILE* fp = fopen(filename,"r");
    
    int n;
    fscanf(fp,"%d",&n); // return number of reads
    printf("%d\n",n);
    
    WeightedQuickUnion* wquickunion = new WeightedQuickUnion(n);
    int p,q;
    // don't use feof() if using, fp will stop pass EOF, not stop at EOF
    // so you will double print the last line
    while(fscanf(fp,"%d %d", &p,&q) != EOF){
        if(wquickunion->connected(p,q)){
            continue;
        }
        wquickunion->uni(p,q);
        printf("%d %d\n",p,q);
    }
    printf("%d components\n", wquickunion->count());
    
    delete wquickunion;

    fclose(fp);

    return 0;
}
