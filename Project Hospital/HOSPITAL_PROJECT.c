#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct info
{
    char name[50];
    char phone_number[100];
    struct info *next;
}info;
info *head=NULL;

typedef struct doctor{
    char name[50];
    struct doctor *next;
}doctor;

doctor *doc_head=NULL;
int gob_num=5;

char doc_name[4][100] = {
              {'N','a','s','i','m',' ','K','h','a','n'},
              {'S','h','u','b','r','a','t','a',' ','B','a','s','u'},
              {'N','a','n','d','a','n','i',' ','R','o','y'},
              {'P','r','a','b','i','r',' ','D','a','s'}
};

void welcome_massege(){
     printf("\n\n\n");
     printf("                :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: ::\n");
     printf("                ::                                              ::\n");
     printf("                ::                      *                       ::\n");
     printf("                ::                     * *                      ::\n");
     printf("                ::                    *   *                     ::\n");
     printf("                ::                   *     *                    ::\n");
     printf("                ::           :: ::  * :: :: * :: :: ::          ::\n");
     printf("                ::           ::                     ::          ::\n");
     printf("                ::           ::     WELCOME TO      ::          ::\n");
     printf("                ::           ::    THE HOSPITAL     ::          ::\n");
     printf("                ::           ::                     ::          ::\n");
     printf("                ::           :: ::  ::  :: :: :: :: ::          ::\n");
     printf("                ::                                              ::\n");
     printf("                ::                                              ::\n");
     printf("                ::                                              ::\n");
     printf("                ::                                              ::\n");
     printf("                :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: \n\n\n");

}


void creat(){
   int num;
   info *newNode, *temp;

   head = (info*)malloc(sizeof(info));

   strcpy(head->name,"----");
   strcpy(head->phone_number,"----");
   head->next=NULL;
   temp=head;

   for(int i=2;i<=4;i++){
      newNode = (info*)malloc(sizeof(info));

      strcpy(newNode->name,"----");
      strcpy(newNode->phone_number,"----");
      newNode->next=NULL;

      temp->next=newNode;
      temp = temp->next;
   }

}
void creat_doc(int n){
   int num;
   doctor *newNode,*temp;

   doc_head = (doctor*)malloc(sizeof(doctor));

   printf("\n    Enter 1 Doctor name: ");
   scanf("%s",doc_head->name);
   doc_head->next = NULL;

   temp = doc_head;

   for(int i=2;i<=n;i++){
    newNode = (doctor*)malloc(sizeof(doctor));

    printf("\n    Enter %d Doctor Name: ",i);
    scanf("%s",newNode->name);

    newNode->next=NULL;
    temp->next=newNode;
    temp=temp->next;
   }

}
void connectExtraDocPatient(int n){
    info *temp, *newNode;
    temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    for(int j=1;j<=n;j++){
        newNode = (info*)malloc(sizeof(info));

        strcpy(newNode->name,"----");
        strcpy(newNode->phone_number,"----");
        newNode->next=NULL;

        temp->next=newNode;
        temp = temp->next;
    }
}
void insertAnyWhere(int n){
    info *temp;
    temp = head;

    for(int i=1;i<=4;i++){
        if(i==n){
            printf("\n\tEnter Patient Name: ");
            scanf("%s",temp->name);

            printf("\tEnter Patient Phone Number: ");
            scanf("%s",temp->phone_number);
            printf("\n\n\tYour Appointment Successfully Recorded!! :)\n\n");
            break;
        }
        else{
            temp=temp->next;
        }
    }
}
void insertNewDocPatient(int n){
    info *temp;
    temp = head;

    for(int i=1;i<n;i++){
        temp=temp->next;
    }
    printf("\n\tEnter Patient Name: ");
    scanf("%s",temp->name);

    printf("\tEnter Patient Phone Number: ");
    scanf("%s",temp->phone_number);
    printf("\n\n\tYour Appointment Successfully Recorded!! :)\n\n");
}
void display(){
   info *temp;
   temp = head;

   for(int i=0;i<4;i++){
     printf("\n\t%d. %s\n",i+1,doc_name[i]);
     printf("\t\tPatient Name: %s\n",temp->name);
     printf("\t\tPatient Number: %s\n\n",temp->phone_number);

     temp= temp->next;
   }
}
void doc_display(){
    doctor *temp;
    temp = doc_head;
    gob_num=5;

    while(temp!=NULL){
    printf("\t%d. %s\n",gob_num,temp->name);

    temp= temp->next;
    gob_num++;
   }
}
void extraDocDisplay(){
    info *temp;
    temp = head;
    int t=4;

    while(t--){
        temp=temp->next;
    }

    doctor *pos;
    pos = doc_head;
    int p=5;

    while(pos!=NULL){
        printf("\n\t%d. %s\n",p,pos->name);
        printf("\t\tPatient Name: %s\n",temp->name);
        printf("\t\tPatient Number: %s\n\n",temp->phone_number);

        temp = temp->next;
        pos = pos->next;
        p++;
    }
}
int checkDocFree(int n){
    info *temp;
    temp = head;

    int i=1;
    while(i<=4){
        if(i!=n){
             temp=temp->next;
        }
        else if(i==n && strcmp(temp->name,"----")==0){
            printf("\n\tYour Doctor Free. You can make an Appointment :)\n\n");
            return -1;
        }
        i++;
    }
    printf("\n\tSorry!! Your Doctor is not Free Now. :(\n\n");
    return -2;
}

int checkfree(int n){
    doctor *temp;
    temp = doc_head;

    for(int i=5;i<=n;i++){
        if(i!=n){
            temp= temp->next;
        }else if(i==n && temp!=NULL){
            printf("\n\tYour Doctor Free. You can make an Appointment :)\n\n");
            return -1;
        }
    }
    printf("\n\tSorry!! Your Doctor is not Free Now. :(\n\n");
    return -2;
}

int main(){

    system("color B");
    welcome_massege();

    creat();

    int n;
    while (1){
    printf("                ===================================================\n");
    printf("                ::        => Who Are You ?:                      ::\n");
    printf("                ::        1.Patient                              ::\n");
    printf("                ::        2.Authority                            ::\n");
    printf("                ::        3.Exit Hospital                        ::\n");
    printf("                ===================================================\n");
    printf("\nEnter Your Choise: ");
    scanf("%d",&n);

    if(n==1){
        printf("\n     ****************** PATIENT AREA *******************\n");
        int a,b,c,d;

        while(1){
            printf("\nSelect your doctor to book an appoinment\n\n");
            printf("   \t1. Nasim Khan\n   \t2. Shubrata Basu\n   \t3. Nandani Roy\n   \t4. Probir Das\n");

            if(doc_head!=NULL){
                doc_display();
            }
            printf("\n\t%d. Check Your Doctor Available Or Not: ",gob_num);
            printf("\n\n00. Back to main menu\n");
            printf("\nEnter your Choise:");
            scanf("%d",&a);

           if(a<=4 && a>0){
              insertAnyWhere(a);              //    This section provide, input data on linked list.
           }
           else if(a>4){

            if(a==gob_num){
            printf("\n\nEnter Doctor SI No.\n");
            printf("   \t1. Nasim Khan\n   \t2. Shubrata Basu\n   \t3. Nandani Roy\n   \t4. Probir Das\n");

              if(doc_head!=NULL){
                  doc_display();
              }
              printf("SL No.: ");
              scanf("%d",&c);

              if(c>4){
                 checkfree(c);                 //    This section just check the data for make is sure Doctor Available Or Not.
              }
              else if(c<=4){
               checkDocFree(c);
              }

              }
              else{
                 insertNewDocPatient(a);
              }

           }
           else if(a==00){
            break;
           }
        }
      }

      else if(n==2){
        printf("\n      ******************* AUTHORITY AREA *******************\n\n");
        int doc_num;
        int pass, flag=0;
        printf("           Enter Password: ");
        scanf("%d",&pass);

        if(pass==1234){
        int ac;

           while(1){
             printf("\n\n        1. Clear all Appointment.\n        2. Check all Appoimnent.\n        3. Appoint New Doctor.\n\n0. Back to manu.\n");
             printf("\nEnter Your Choice: ");
             scanf("%d",&ac);

             if(ac==1){                            //    Firstly, this section free/clear head and then create a new linked list.
                free(head);
                creat();
                connectExtraDocPatient(doc_num);
                printf("\n\nAll Appointments are Clear!! ");
             }

             else if(ac==2){                      //   This section display initial linked list, and  then if extra linked is exist, then
                    display();                    //   print the another linked List.
                    extraDocDisplay();
             }

             else if(ac==3){
                printf("\n\n\tHow many doctors to appoint: ");
                scanf("%d",&doc_num);                               //   This section make a new Liked list and connect it to the previous.
                creat_doc(doc_num);
                connectExtraDocPatient(doc_num);
                printf("\n\n\tNew Doctors Appointed Successfully!! :)\n\n");
             }

             else if(ac==0){
                break;
             }

           }
        }
        else{
            printf("\nWRONG PASSWORD!! :(\n\n");
        }
      }
    else if(n==3){
        printf("\n\t Thanks for coming :)\n\n");
        break;
    }

   }
   return 0;
}

