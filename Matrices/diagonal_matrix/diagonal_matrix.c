#include <stdio.h>

struct Matrix{
    int arr[10];
    int n;
};

void set (struct Matrix *m, int i , int j , int value){
    if (i == j){
        m->arr[i - 1] = value;
    }
}
int get (struct Matrix m, int i, int j){
    if (i == j) {
        return m.arr[i -1];
    }
    else return 0;
}

void display(struct Matrix m){
    for (int i = 0 ; i < m.n ; i++){
        for (int j = 0 ; j < m.n ; j++){
            if (i == j ) {
                printf ("%d ", m.arr[i]);
            }
            else printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    
    struct Matrix m;
    
    m.n = 4;
    
    set (&m, 1,1, 5);
    set (&m, 2,2, 10);
    set (&m, 3,3, 15);
    set (&m, 4,4, 20);
    
    printf ("%d\n", get (m, 3,3));
    printf ("%d\n", get (m ,2,4));    //non diagonal element wll return 0
    
    printf ("\nMatrix: \n");
    display(m);
    
}