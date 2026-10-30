#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertAtBeginning(int value){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        return;
    }
    struct node *last=head;
    while(last->next!=head) {
        last=last->next;
    }
    newNode->next=head;
    last->next=newNode;
    head=newNode;
}
void insertAtEnd(int value){ 
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        return;
    }
    struct node *current=head;
    while(current->next!=head){
        current=current->next;
    }
    current->next=newNode;
    newNode->next=head;
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *current=head;
    while(current->next!=head){
        current=current->next;
    }
    struct node *temp=head;
    head=head->next;
    current->next=head;
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *current=head;
    while(current->next->next!=head){
        current=current->next;
    }
    free(current->next);
    current->next=head;
}
void insertInMiddle(int value, int position){
    if(position<1){
        printf("Invalid position\n");
        return;
    }
    if(position==1){
        insertAtBeginning(value);
        return;
    }
    if(head==NULL ){
        printf("List is empty\n");
        return;
    }
    struct node *current=head;
    int i;
    for(i=1;i<position-1 && current->next!=head;i++){
        current=current->next;
    }
    if(i < position - 1){
        printf("Position out of bounds\n");
        return;
    }
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=value;
    newNode->next=current->next;
    current->next=newNode;
}
void deleteFromMiddle(int pos){
    if(pos<1){
        printf("Invalid position\n");
        return;
    }
    if(head==NULL ){
        printf("List is empty\n");
        return;
    }
    if(pos==1){
        deleteAtBeginning();
        return;
    }
    struct node *current=head;
    for(int i=1;i<pos-1 && current->next!=head;i++){
        current=current->next;
    }
    if(current->next==head){
        printf("Position out of bounds\n");
        return;
    }
    struct node *temp=current->next;
    current->next=temp->next;
    free(temp);
}
void search(int value){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    struct node *current=head;
    int position=1;
    do{
        if(current->data==value){
            printf("Value %d found at position %d\n",value,position);
            return;
        }
        current=current->next;
        position++;
    }while(current!=head);
    printf("Value %d not found in the list\n",value);
}
void display(){
    if(head==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    struct node *current = head;
    printf("Linked list elements:\n");
    do {
        printf("%d\n", current->data);
        current = current->next;
    } while (current != head);
}
void insert(int value){
    if(head==NULL){
        insertAtBeginning(value);
        return;
    }
    insertAtEnd(value);
}
int main(){
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    if(first==NULL || second==NULL || third==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    first->data=10;
    second->data=20;
    third->data=30;
    first->next=second;
    second->next=third;
    third->next=first;
    head=first;
    int choice,value,position;
    do{
        printf("Enter your choice\n(1.Insert at beginning,\n2.Insert at end,\n3.Delete at beginning,\n4.Delete at end,\n5.Insert in middle,\n6.Delete from middle,\n7.Search,\n8.Display,\n9.Insert Data,\n10.Exit.): ");
        scanf("%d",&choice); 

        switch(choice){        
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d",&value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                insertAtEnd(value);
                break;

            case 3:
                deleteAtBeginning();
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                printf("Enter value and position to insert in middle: ");
                scanf("%d %d",&value,&position);
                insertInMiddle(value,position);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d",&position);
                deleteFromMiddle(position);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d",&value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;

            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
}while(choice!=10);
while (head != NULL) {
        deleteAtBeginning();
    }

return 0;
}