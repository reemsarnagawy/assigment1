#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
        tail=head;
        return;
    }
   tail->next=newNode;
    tail=newNode;
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
while (1)
    { struct student x;
    printf("if you want to insert in first press 1\n");
    printf( "if you want to insert in End press 2\n");
    printf("if you want to insert in middle press 3\n");
    printf("if you want to display press 4\n");
    printf("if you want to Exit press 5\n");
    printf("if you want to calc time to insert element in first press 6\n");
    printf("if you want to calc time to insert element in last press 7\n");
    printf("if you want to calc time to insert element in position press 8\n");
    int y;
    scanf("%d" , &y);
    switch(y){
        case 1: printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");
                scanf("%s", &x.name);//you must enter (_)between the first and second name
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
                    break;
        case 2: printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");//you must enter (_)between the first and second name
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
                    break;
        case 3: printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");//you must enter (_)between the first and second name
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
                    break;
        case 4: displayList();
                break;
        case 5: exit(0); 
        case 6:  printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");
                scanf("%s", &x.name);//you must enter (_)between the first and second name
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
                int start=clock();
                insert_first( x);
                int finish=clock();
                printf("the time taken by linked list to insert in the firist=%f",(double)(finish-start)/CLOCKS_PER_SEC);
                printf("                                                       ");
                break;
        case 7: printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");//you must enter (_)between the first and second name
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
                int start2=clock();
                insert_END(x);
                int finish2=clock();
                printf("the time taken by linked list to insert in the End=%f",(double)(finish2-start2)/CLOCKS_PER_SEC);
                printf("                                                       ");
                break;
        case 8:  printf("Enter ID: ");
                scanf("%d", &x.id);
                printf("Enter name: ");//you must enter (_)between the first and second name
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
                int u1;
                printf("enter the position which want to insert in it of list\n");
                scanf("%d" , &u1);
                int start3=clock();
                insert_middle(u1 , x);
                int finish3=clock();
                printf("the time taken by linked list to insert in the position 3=%f",(double)(finish3-start3)/CLOCKS_PER_SEC);
                printf("                                                       ");
                break;            
                    
        default:printf("you must enter a correct number\n");

    }
    }
  return 0;}





void dynamic_array()
 {   struct student *x;
 struct student *y;
    int i;
    printf("enter size of array ");
    scanf("%d",&n);
     x =(struct student*) malloc(n*sizeof(struct student));

    for( i=0;i<n;i++){
        printf("Enter name of student number %d  ",i+1);
        scanf("%s", x[i].firstName);
        printf("Enter ID of student number %d  ",i+1);
        scanf("%d", &x[i].ID);
        printf("Enter score of student number %d  ",i+1);
        scanf("%d", &x[i].score);
         printf("Enter day of birth of student number %d  ",i+1);
           scanf("%d", &x[i].bir.day);
         printf("Enter month of birth of student number %d  ",i+1);
        scanf("%d", &x[i].bir.month);
         printf("Enter year of birth of student number %d  ",i+1);
        scanf("%d", &x[i].bir.year);}
  int k,z;
    y =(struct student*) realloc(x,(n+1)*sizeof(struct student));
    for(int i=0;i<n;i++)
    {
        y[i]= x[i];
     
        
    }
            for(int i=0;i<n;i++){
printf("name of student %d\n",i+1);
            printf("%s\n",x[i].firstName);
            printf("id of student %d\n",i+1);
            printf("%d\n",x[i].ID);
            printf("score of student %d\n",i+1);
              printf("%d\n",x[i].score);
              printf("birthday of student %d\n",i+1);
                printf("%d\n",x[i].bir.day);
                printf("month of student %d\n",i+1);
                  printf("%d\n",x[i].bir.month);
                   printf("year of student %d\n",i+1);
                    printf("%d\n",x[i].bir.year);
        }
 
               printf("if you want to insert at the beginning press 1 \n");
printf("if you want to insert at the midle press 2 \n");
printf("if you want to insert at the end press 3 \n");
      scanf("%d",&k);
       int m=n+1;
if(k==1)
{z=0;
  for(i=n+1;i>0;i--)
     {

       y[i]=y[i-1];

     }
     printf("Enter name of new student  ");
     scanf("%s", y[0].firstName);
        printf("Enter ID of new student  ");
        scanf("%d", &y[0].ID);
        printf("Enter score of new student  ");
        scanf("%d", &y[0].score);
         printf("Enter day of birth of new student  ");
           scanf("%d", &y[0].bir.day);
         printf("Enter month  of new student  ");
        scanf("%d", &y[0].bir.month);
         printf("Enter year of new student  ");
        scanf("%d", &y[0].bir.year);
    
}
       else if(k==2)
       {
  for(i=n+1;i>(n/2);i--)
     {

       y[i]=y[i-1];

     }
      printf("Enter name of new student  ");
     scanf("%s", y[n/2].firstName);
        printf("Enter ID of new student  ");
        scanf("%d", &y[n/2].ID);
        printf("Enter score of new student  ");
        scanf("%d", &y[n/2].score);
         printf("Enter day of birth of new student  ");
           scanf("%d", &y[n/2].bir.day);
         printf("Enter month  of new student  ");
        scanf("%d", &y[n/2].bir.month);
         printf("Enter year of new student  ");
        scanf("%d", &y[n/2].bir.year);
                
       }
        else{
  for(i=n+1;i>n;i--)
     {

       y[i]=y[i-1];

     }
      printf("Enter name of new student  ");
     scanf("%s", y[n].firstName);
        printf("Enter ID of new student  ");
        scanf("%d", &y[n].ID);
        printf("Enter score of new student  ");
        scanf("%d", &y[n].score);
         printf("Enter day of birth of new student  ");
           scanf("%d", &y[n].bir.day);
         printf("Enter month  of new student  ");
        scanf("%d", &y[n].bir.month);
         printf("Enter year of new student  ");
        scanf("%d", &y[n].bir.year);
                  
        }
        for(int i=0;i<=n;i++){
printf("name of student %d\n",i+1);
            printf("%s\n",y[i].firstName);
            printf("id of student %d\n",i+1);
            printf("%d\n",y[i].ID);
            printf("score of student %d\n",i+1);
              printf("%d\n",y[i].score);
              printf("birthday of student %d\n",i+1);
                printf("%d\n",y[i].bir.day);
                printf("month of student %d\n",i+1);
                  printf("%d\n",y[i].bir.month);
                   printf("year of student %d\n",i+1);
                    printf("%d\n",y[i].bir.year);
        }
 


 }



int main() { 
    printf("how are you:\n");
int start=clock();
dynamic_array();
int finish=clock();
printf("the time taken by dynamic array = %f",(double)(finish-start)/CLOCKS_PER_SEC);
return 0;
}
