#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct gerbong{
    int value;
    struct gerbong *next;
}gerbong;

typedef struct queue{
    gerbong *head;
    gerbong *tail;
} queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}


bool push_front(queue *q, int value){
    gerbong *newnode = (gerbong*) malloc(sizeof(gerbong));

    if(newnode == NULL) return false;

    //set newnode to be the head
    if(q->head == NULL){
        newnode->value = value;
        q->head = newnode;
        newnode->next = NULL;
    }
    else{
    newnode->value = value;
    newnode->next = q->head;
    q->head = newnode;
    }

    if(q->tail == NULL){
        q->tail = newnode;
    }

}

bool push_back(queue *q, int value){
    gerbong *newnode = (gerbong*) malloc(sizeof(gerbong));

    if (newnode == NULL) return false;

    newnode->value = value;
    newnode->next = NULL;

    
    if(q->tail != NULL){
        q->tail->next = newnode;
    }
    q->tail = newnode;

    
    if(q->head == NULL){
        q->head = newnode;
    }
    return true;
}

void delete(queue *q, int value){

    gerbong *curr = q->head;

    while(curr!= NULL){
        if(curr->next->value == value){
            gerbong *temp = curr->next;
            curr->next = temp->next;
            temp = NULL;
            return;
        }
    }
    curr = curr->next;

}

void find(queue *q, int value){
    
    gerbong *curr = q->head;
    int found = 0;
    int count = 0;
    while(curr!= NULL){
        if(curr->value == value){
            found = 1;
            break;
        }
        count ++;
        curr = curr->next;
    }

    if(found == 1){
        printf("FOUND %d\n", count);
    }
    else{
        printf("NOT FOUND\n");
    }

}

void print_list(queue *q, int *order2, int *jenis2){

    gerbong *curr = q->head;
    printf("LIST ");
    
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }

    printf("\n");
    
}

void execute(int Q, int *order2, int *jenis2){
    
    queue q1;
    init_queue(&q1);


    for(int i = 0;i <= Q-1;i++){
        
        if(order2[i] == 1){
            push_front(&q1, jenis2[i]);
        }
        else if(order2[i] == 2){
            push_back(&q1, jenis2[i]);
        }
        else if(order2[i] == 3){
            delete(&q1, jenis2[i]);
        }
        else if(order2[i] == 4){
            find(&q1, jenis2[i]);
        }
    
    }

    print_list(&q1, order2, jenis2);
}

int main(){

    int Q = 0;
    scanf("%d ", &Q);

    int order2[Q];
    int jenis2[Q];

    for(int i = 0; i <= Q-1;i++){
        int order = 0;
        int jenis = 0;
        scanf("%d %d",&order, &jenis);
        order2[i] = order;
        jenis2[i] = jenis;
    }


    execute(Q, order2, jenis2);


}
