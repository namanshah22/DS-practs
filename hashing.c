#include <stdio.h>
#include <stdlib.h>

int hash_table[100], n;

int hash(int key, int i){
    int position = ((key % n) + i) % n;
    return position;
}

void display(){
    printf("\n");
    for(int i=0; i<n; i++){
        if(hash_table[i] != -1){
            printf("%d. %d\n",i,hash_table[i]);
        }
        else{
            printf("%d. NULL\n",i);
        }
    }
    printf("\n");
}

void main(){
    int flag = 1, choice, key;
    printf("\nEnter The size of hash table : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        hash_table[i] = -1;
    }
    while(flag){
        printf("\nEnter\n1.Insert\n2.Display\n3.Exit\n : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int i=0;
                printf("Enter Key : ");
                scanf("%d", &key);
                for(; i<n; i++){
                    int position = hash(key, i);
                    if (hash_table[position] == -1){
                        hash_table[position] = key;
                        printf("\nInserted\n");
                        break;
                    }
                }
                if(i >= n){
                    printf("\nCan't be inserted\n");
                }
                break;
            }
            case 2:{
                display();
                break;
            }
            case 3:{
                flag = 0;
                break;
            }
            default: printf("\nWrong input\n");
        }
    }
}