#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data ;
    int index;
    struct node * link ;
};

struct Queue{
    struct node *front, *rear;
};

void initQueue(struct Queue *Q){
        (Q)->front = (Q)->rear = NULL;
}

void enQueue(struct Queue *Q, int ele, int index){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = ele;
    nn->index = index;
    
    if(!(Q->front)){
        Q->rear = Q->front = nn->link = nn;
        return;
    }
    nn->link = Q->front;
    Q->rear->link = nn;
    Q->rear = nn;
}

int isEmpty(struct Queue Q){
    if(Q.front)
        return 0;
    return 1;
}

struct node deQueue(struct Queue *Q){
    struct node ret;
    ret.data = Q->front->data;
    ret. index = Q->front->index;
    
    if(Q->front->link == Q->front){
        Q->rear = Q->front = NULL;
    }
    else{
        Q->front = Q->front->link;
        Q->rear->link = Q->front;
    }
    return ret;
}

struct node enquire(struct Queue Q){
    struct node ret;
    ret.data = Q.front->data;
    ret.index = Q.front->index;
    return ret;

}

int main(){
    int n, t, i = 0, m, temp;
    char s_temp[1000];
    scanf("%d%d%d",&n,&t,&m);
    struct Queue Q[2];
    
    int result[100000] = { 0 };
    
    initQueue(&Q[0]);
    initQueue(&Q[1]);
    
    
    
    while( i < m){
        scanf("%d %s",&temp, s_temp);
        if(s_temp[0]=='l')
            enQueue(&Q[0], temp, i);
        else
            enQueue(&Q[1], temp, i);
        i++;
    }

    int first, time = 0, curr = 0; // 0  means left
    
    printf("The unloaded time");

    while(!(isEmpty(Q[0]) && isEmpty(Q[1]))){
        
        first = INT_MAX ;
        
        if(!isEmpty(Q[0]))
            first = enquire(Q[0]).data;
        if(!isEmpty(Q[1]))
            first = (first > enquire(Q[1]).data) ? enquire(Q[1]).data : first;
        
        time = (first > time) ? first : time;
        i = 0;
        
        while(!isEmpty(Q[curr]) &&  i < n  &&  enquire(Q[curr]).data <= time){
            result[enquire(Q[curr]).index] = time + t;
            deQueue(&Q[curr]);
            ++i;
        }
        
        time += t;
        curr = ( curr == 0 ) ? 1 : 0;
    }

    for( i = 0; i < m; i++)
        printf("\n%d",result[i]);

    return 0;
}
