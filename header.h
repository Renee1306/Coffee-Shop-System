void main();
void staffpassword();
void staffMenu();
void registeredcusMenu();
void staffadd();
void staffdelete();
void staffupdate();
void staffcreate();
void newcusregister();
void registeredmodify();
void registeredorder();
void registeredcancel();
void registeredreceipt();
void back();
void staffdelete();
void staffsearchitem();
void staffsearchcode();
void staffsearchname();
void backsearch();
void print_table();
void save();
void staffsearchorder();
void save1();
void back1();
void readcus();
void registercuslogin();
void readcusorder();
void save2();
void readmenu();
void readcus1();

struct menu {
    int category;
    char   code[10];
    char  name[20];
    float  price;
} or [100];

struct menu1 {
    int category;
    char   code[10];
    char  name[20];
    float  price;
} or1 [100];

struct account {
    char cusid[10];
    char name[20];
    char username[20];
    int contactno;
    char email[20];
    int password;
}acc[100];

struct account1 {
    char cusid[10];
    char name[20];
    char username[20];
    int contactno;
    char email[20];
    int password;
}acc1[100];

struct order
{
    int ordercode;
    char cusid[20];
    char cusname[20];
    char itemid[20];
    char itemname[20];
    int quantity;
    float price;
    char paymentmethod[20];
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
}ord[100];

