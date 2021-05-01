#include <stdio.h>
#include <stdlib.h>
struct birth {
int day;
int month;
int year;
}bir;
struct student {
    char name [50];
    int id;
    int score_last_year;
    struct birth bir;
}data;
struct node {
   struct student data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

 void insert_first( struct student z){
     struct node*newnode=(struct node*)malloc(sizeof(struct node));

     if(head == NULL)
     {

         newnode->data=z;
         newnode->next= NULL;
         head=newnode;
         tail=head;

     }
     else
     {
     newnode->data=z;
     newnode->next=head;
     head=newnode;
     }
 }
 void insert_END(struct student z)
 {
     struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = z;
    newNode->next = NULL;

    //need this if there is no node present in linked list at all
    if(head==NULL){
        head = newNode;
        head = tail;
        return;
    }
   tail->next=newNode;
    tail=newNode;

//    struct node* temp = head;
//
//    while(temp->next!=NULL)
//        temp = temp->next;
//
//    temp->next = newNode;
}
int calcSize(struct node *num){
    int size=0;

    while(num!=NULL){
        num = num->next;
        size++;
    }
    return size;
}
void insert_middle(int pos,  struct student x)
{
    int size = calcSize(head);

    //If pos is 1 then should use insertStart method
    //If pos is less than or equal to 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if(pos<1 || size < pos)
    {
        printf("Can't insert, %d is not a valid position\n",pos);

    }
    else
    {
        struct node* temp = head;
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        while(--pos)
        {
            temp=temp->next;
        }
        //(25)->next = 10 as 12->next is 10
        newnode->next= temp->next;
        // (12)->next = 25
        temp->next = newnode;
        //new node added in b/w 12 and 10
    }
}

void displayList()
{
    struct node *tmp;
    if(head == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" ID = %d\n", tmp->data.id); // prints the data of current node
            printf(" name = %s\n",&tmp->data.name);
            printf(" score_last_year = %d\n", tmp->data.score_last_year);
            printf(" day = %d\n", tmp->data.bir.day);
            printf(" month = %d\n", tmp->data.bir.month);
            printf(" year = %d\n", tmp->data.bir.year);
            tmp = tmp->next;                     // advances the position of current node
        }
    }
}


int main()
{

    int n;
    printf("enter the size of list\n");
    scanf("%d" , &n);
    for(int i=0; i<n; i++)
    { struct student x;
    printf("if you want to insert in first press 1\n");
    printf( "if you want to insert in End press 2\n");
    printf("if you want to insert in middle press 3\n");
    int y;
    scanf("%d" , &y);

                if(y==1)
                {
                    printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");
                scanf("%s", &x.name);
                fflush(stdin);
                printf("Enter score: ");
                scanf("%d",&x.score_last_year);
                fflush(stdin);
                printf("Enter day: ");
                scanf("%d", &x.bir.day);
                fflush(stdin);
                printf("Enter month: ");
                scanf("%d", &x.bir.month);
                printf("Enter year: ");
                scanf("%d", &x.bir.year);
                fflush(stdin);
                    insert_first( x);
                }
                else if(y==2)
                {printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");
                scanf("%s", &x.name);
                fflush(stdin);
                printf("Enter score: ");
                scanf("%d",&x.score_last_year);
                printf("Enter day: ");
                scanf("%d", &x.bir.day);
                printf("Enter month: ");
                scanf("%d", &x.bir.month);
                printf("Enter year: ");
                scanf("%d", &x.bir.year);
                fflush(stdin);
                    insert_END(x);
                }
                else if(y==3)
                {printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");
                scanf("%s", &x.name);
                fflush(stdin);
                printf("Enter score: ");
                scanf("%d",&x.score_last_year);
                printf("Enter day: ");
                scanf("%d", &x.bir.day);
                printf("Enter month: ");
                scanf("%d", &x.bir.month);
                printf("Enter year: ");
                scanf("%d", &x.bir.year);
                fflush(stdin);
                    int u;
                    printf("enter the position which want to insert in it of list\n");
                    scanf("%d" , &u);
                    insert_middle(u , x);
                }
                else {
                printf("you must enter a correct number\n");
                i--;}

    }
    displayList();

       return 0;
    }
