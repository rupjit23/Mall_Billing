#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#define LENGTH_USER 20
#define MAX_CUSTOMER_LENGTH 100


typedef struct {
    int age;
    long long int contact_no;
    char first_name[LENGTH_USER];
    char middle_name[LENGTH_USER];
    char last_name[LENGTH_USER];
    char address[LENGTH_USER];
    long long int total_budget;
}User;

User customer[MAX_CUSTOMER_LENGTH];
int customer_count=0;
int index_number;

void user_register();
void show_the_details_of_mall();
void show_some_space();
int generate_bill();
void get_date();
void show_current_previous_bill();
void show_customer_details();

int main()
{
    char date[100];
    int age;
    long long int contact_no;
    char first_name[LENGTH_USER];
    char middle_name[LENGTH_USER];
    char last_name[LENGTH_USER];
    char address[LENGTH_USER];
    long long int total_budget=0;
    long int current_bill;
    get_date(date);
    show_the_details_of_mall();
    user_register(first_name,middle_name,last_name,contact_no,age,address);
    show_some_space();
    current_bill=generate_bill();
    show_current_previous_bill(current_bill,total_budget,date);
    show_some_space();
    show_customer_details();
    
}

void show_the_details_of_mall()
{
    printf("---------------------Welcome to our Mall-------------------------------");
    printf("\n");

}

void show_some_space()
{
    printf("-------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------\n");
    printf("\n");
}
void user_register(char *first_name,char *middle_name,char *last_name,long long contact_no,int age,char *address)
{
    if(customer_count == MAX_CUSTOMER_LENGTH)
    {
        fprintf(stderr,"MAX Size of customer excedded");
    }
    int new_index=customer_count;
    printf("Enter your first_Name: ");
    scanf("%s",first_name);
    strcpy(customer[new_index].first_name, first_name);
    printf("Enter your middle name (press Enter to skip): ");
    getchar(); // flush newline
    fgets(middle_name, LENGTH_USER, stdin);
    middle_name[strcspn(middle_name, "\n")] = '\0'; 
    strcpy(customer[new_index].middle_name, middle_name);
    printf("Enter your last_Name: ");
    scanf("%s",last_name);
    strcpy(customer[new_index].last_name, last_name);
    printf("Please enter your mobile number: ");
    scanf("%lld",&contact_no);
    customer[new_index].contact_no = contact_no;
    printf("Please enter your age: ");
    scanf("%d",&age);
    if((age < 0) || (age > 120))
    {
        printf("Please enter a valid age: ");
        scanf("%d",&age);
    }
    customer[new_index].age = age;
    printf("Please enter your address: ");
    scanf("%s",address);
    strcpy(customer[new_index].address, address);
}

int generate_bill(){
    int choice,bill_money=0;
    int count=0;
    printf("Please enter how many things have you choosen: ");
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
    printf("1: Dress\n");
    printf("2: Toy\n");
    printf("3: Bottle\n");
    printf("4: Computer\n");
    printf("5: Mobile\n");
    printf("Please choose what have you choosen: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
       bill_money=bill_money+500;
        break;
    case 2:
        bill_money=bill_money+700;
         break;
    case 3:
        bill_money=bill_money+200;
          break;
    case 4:
        bill_money=bill_money+50000;
           break;
    case 5:
        bill_money=bill_money+10000;
            break;
    default: 
        return 0;
    }
    printf("Your bill after taking item %d is: %d\n\n",choice,bill_money);
    }
    return bill_money;
}

void get_date(char *store_date)
{
    time_t raw_time;
    struct tm *current_date;
    time(&raw_time);
    current_date=localtime(&raw_time);
    strftime(store_date,100,"%d %B %Y",current_date);
}

void show_current_previous_bill(long int current_bill,long long int total_budget,char * date)
{
    int new_index=customer_count;
    total_budget=total_budget+current_bill;
   // printf("The bill on %s is: %ld\n",date,current_bill);
    printf("\n");
    printf("Your spend till %s is %lld\n",date,total_budget);
    customer[new_index].total_budget=total_budget;
    customer_count++;
}

void show_customer_details() {
    if (customer_count == 0) {
        printf("No customer data available.\n");
        return;
    }

    for (int i = 0; i < customer_count; i++) {
        printf("Customer #%d\n", i + 1);
        printf("First Name: %s\n", customer[i].first_name);
        printf("Middle Name: %s\n", customer[i].middle_name[0] ? customer[i].middle_name : "N/A");
        printf("Last Name: %s\n", customer[i].last_name);
        printf("Age: %d\n", customer[i].age);
        printf("Contact No: %lld\n", customer[i].contact_no);
        printf("Address: %s\n", customer[i].address);
        printf("Total Budget: %lld\n", customer[i].total_budget);
        printf("-------------------------------------------------\n");
    }
}
