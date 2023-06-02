# include "iGraphics.h"
#include<stdio.h>
#include<string.h>

/*
page = 1 : login,
page = 2: select_meal, total_stock;
*/
//int total_stock_page = 0;
//int select_menu_page = 0;
int page = 1;
int access = 5;
int mode = 0;
int len = 0;
char str[100];
char name_match[100];
char pass_match[100];
char name[100][40];
char password[100][40];
int home_mouse_position = 1;
//int meal_page = 0; //at page 2
int person = 10;
char ingredients[20][20];  //name of each ingredients
double total_amount[20];   //amount of ingredients in particular index of total array
char price[20];

void draw_frontpage()
{
    iShowBMP(0,0,"homepage.bmp");
    iSetColor(25, 0, 51);
	iText(500, 600, "HELLO!CREATE YOUR OWN MESS!",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250, 100, "USERNAME",GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(250,50,370,40);
	iText(800, 100, "PASSWORD",GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(800,50,370,40);
	iText(1210, 25, "ENTER",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(1190,15, 120,40);
}
void draw_homepage()
{
    iClear();
	iSetColor(255, 255, 153);
	//iFilledCircle(30, 640, 20);
	//iFilledCircle(30, 690, 20);
	//iText(60, 685, "SELECT MEALS", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(204, 200, 153);
	//iText(60, 635, "TOTAL STOCK", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(440,80,"chef.bmp");
	iShowBMP(110,150,"add_item.bmp");
	iText(100, 400, "TOTAL STOCK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 110, "ADD ITEMS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1070, 400, "SELECT MEALS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1070, 110, "EXPENDITURE", GLUT_BITMAP_TIMES_ROMAN_24);

}
void login_test();

void read_login()
{
    int i = 0;
    FILE *ptr;
    ptr = fopen("login.txt", "r");
    if(ptr == NULL){
        printf("login file cant be open\n");
        return;
    }
    else{
        printf("opened\n");
    }
    while(!feof(ptr)){

        fscanf(ptr, "%s", &name[i]);
        fscanf(ptr, "%s", &password[i]);
        i++;
    }
    fclose(ptr);

    /*
    for(int j = 0; name[j]!='\0'; j++){
        printf("%s %s\n",name[i], password[i]);
    }
    */

    login_test();
}

void login_test()
{
    for(int i = 0; name[i]!='\0'; i++){
        int x = strcmp(name_match, name[i]);
        int y = strcmp(pass_match, password[i]);

        printf("main %s\n input %s\n%s\n%s\n", name[i], name_match, password[i], pass_match);

        if(x == 0 && y == 0){
           printf("elcome");
           access = 1;
             page = 2;
             break;
        }
        else if(x == 0 && y != 0){
            printf("incorrect");
            access = -1;
        }
        else {
            printf("wrong");
            access = 0;
        }

    }

}


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	int i;
    if(mode == 1)
	{
        if(key == 13)  //enter
        {
            mode = 0;
            if(page == 1){
            if(home_mouse_position == 1)strcpy(name_match,str);
            if(home_mouse_position == 2)strcpy(pass_match, str);
            }

            printf("%s %s\n", name_match, pass_match);
           //printf("%s\n", s2);
            for(i = 0; i < len; i++)
                str[i] = 0;
            len = 0;
        }
        else if(key == 8){
            len--;
            str[len] = '\0';

        }
        else
        {
           str[len] = key;
           len++;
        }
    }

}

void show_total_stock()
{
    //total_stock_page = 1;

    //iClear();
    int k = 0;
    for(int i = 0; total_amount[i] != '\0'; i++){
        char s[10];
        sprintf(s, "%lf", total_amount[i]);
        iText(60, 690 - k, ingredients[i] , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(180, 690 - k, s , GLUT_BITMAP_TIMES_ROMAN_24);
        //printf("%s %lf\n", ingredients[i], total_amount[i]);
        k += 30;
    }

}

void read_total_stock(){
    int i = 0;
    FILE *ptr;
    ptr = fopen("total_stock.txt", "r");
    if(ptr == NULL){
        printf("total_stock file cant be open\n");
        return;
    }
    else{
        printf("opened\n");
    }
    while(!feof(ptr)){

        fscanf(ptr, "%s", &ingredients[i]);
        fscanf(ptr, "%lf", &total_amount[i]);
        i++;
    }

    //total_stock_page = 2;
    //show_total_stock();

}

void click_total_stock(int mx, int my)
{
    //total_stock_page = 1;
    if(mx >= 100 && mx <= 150 && my >= 400 && my <= 450){
     page = 8;
    read_total_stock();
    }
    printf("%d stock pafe\n", page);
}

void click_select_menu(int mx, int my)
{
     //total_stock_page = 0;
    if(mx >= 1070 && mx <= 2100 && my >= 400 && my <= 450){
    page = 3;
    }
}

void draw_options()
{
    iText(600, 450, "FEAST", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 200, "REGULAR", GLUT_BITMAP_TIMES_ROMAN_24);
}

void click_options(int mx, int my)
{
    printf("before click %d\n", page);
    if(mx >= 600 && mx <= 700 && my >= 450 && my <= 470){
    page = 4;
    }
    if(mx >= 600 && mx <= 700 && my >= 200 && my <= 230){
    page = 5;
    }
    printf("after click %d\n", page);
}

void click_time(int mx, int my)
{
     printf("click time before %d\n",page);
    if(mx >= 600 && mx <= 700 && my >= 430 && my <= 450 && page==5){
    page = 6;
    }
    if(mx >= 600 && mx <= 700 && my >= 330 && my <= 350 && page==5){
    page = 7;
    }
    if(mx >= 600 && mx <= 700 && my >= 230 && my <= 250 && page==5){
    page = 9;
    }
     printf("click time after %d\n",page);
}

void draw_time()
{

    iClear();
	iSetColor(255, 255, 153);
    iText(600, 430, "BREAKFAST", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 330, "LUNCH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 230, "DINNER", GLUT_BITMAP_TIMES_ROMAN_24);

}

void totalstock_store()
{
    int i = 0;
    FILE *ptr;
    ptr = fopen("total_stock.txt", "r+");
    if(ptr == NULL){
        printf("total_stock file cant be open\n");
        return;
    }
    //else printf("aluvorta opened\n");
    while(!feof(ptr)){

        fscanf(ptr, "%s", &ingredients[i]);
        fscanf(ptr, "%lf", &total_amount[i]);
        i++;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        printf("%s ", ingredients[i]);
        printf("%g\n", total_amount[i]);
    }

}


int aluvorta(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("alu", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_aluvorta()
{

    aluvorta(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int simvorta(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("sim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_simvorta()
{

    simvorta(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int begunvaji(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("begun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_begunvaji()
{

    begunvaji(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}


int ruti(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("ata", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }

    }

}

void update_ruti()
{

    ruti(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int dim(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("dim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*1;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }

    }

}

void update_dim()
{

    dim(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int nastavaji(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("alu", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tomato", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("gajor", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_nastavaji()
{

    nastavaji(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}


int shobji(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("alu", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tomato", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("gajor", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_shobji()
{

    nastavaji(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}


int murgi(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("murgi", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_murgi()
{

    murgi(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int ruimach(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("ruimach", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_ruimach()
{

    ruimach(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int pabdamach(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("pabdamach", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_pabdamach()
{

    pabdamach(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int pangash(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("pangash", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_pangash()
{

    pangash(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int telapia(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("ruimach", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_telapia()
{

    telapia(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}

int vaat(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("chaal", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25;
            if(total_amount[i] < 0) return -1;
        }
    }
}

void update_vaat()
{

    vaat(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}


int daal(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("dal", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.1;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            if(total_amount[i] < 0) return -1;
        }
    }

}

void update_daal()
{

    daal(person);

    int j = 0;
    FILE *ptr2;
    ptr2 = fopen("total_stock.txt", "w+");
    if(ptr2 == NULL){
        printf("total_stock file cant be open\n");
        return;
    }

    for(int i = 0; i < total_amount[i] != '\0'; i++){
        fprintf(ptr2, "%s ", ingredients[i]);
        fprintf(ptr2, "%g\n", total_amount[i]);
    }

    fclose(ptr2);
}


void click_breakfast(int mx, int my){
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620)
    update_ruti();
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540)
    update_nastavaji();
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490)
    update_dim();

}

void draw_breakfast(){
    iClear();
	iSetColor(255, 255, 153);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 580, "RUTI", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 585, 20);
	iText(80, 500, "VAJI", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 505, 20);
	iText(80, 450, "DIM", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 455, 20);

}



void click_dinner(int mx, int my){
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620)
    update_vaat();
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540)
    update_murgi();
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490)
    update_daal();
    if(mx >= 80 && mx <= 140 && my >= 370 && my <= 410)
    update_aluvorta();
    if(mx >= 80 && mx <= 140 && my >= 320 && my <= 360)
    update_simvorta();
    if(mx >= 80 && mx <= 140 && my >= 270 && my <= 310)
    update_begunvaji();
}


void draw_dinner(){
    iClear();
	iSetColor(255, 255, 153);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 585, 20);
	iText(80, 500, "CHICKEN", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 505, 20);
	iText(80, 450, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 455, 20);
	iText(80, 370, "ALU VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 375, 20);
	iText(80, 320, "SIM VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 325, 20);
	iText(80, 270, "BEGUN VAJI", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 275, 20);
}

void click_lunch(int mx, int my){
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620)
    update_vaat();
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540)
    update_daal();
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490)
    update_shobji();
    if(mx >= 80 && mx <= 140 && my >= 370 && my <= 410)
    update_ruimach();
    if(mx >= 80 && mx <= 140 && my >= 320 && my <= 360)
    update_pabdamach();
    if(mx >= 80 && mx <= 140 && my >= 270 && my <= 310)
    update_pangash();
    if(mx >= 80 && mx <= 140 && my >= 220 && my <= 410)
    update_telapia();
}


void draw_lunch(){
    iClear();
	iSetColor(255, 255, 153);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 585, 20);
	iText(80, 500, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 505, 20);
	iText(80, 450, "SHOBJI", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 455, 20);
	iText(80, 370, "RUI MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 375, 20);
	iText(80, 320, "PABDA MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 325, 20);
	iText(80, 270, "PANGASH", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 275, 20);
	iText(80, 220, "TELAPIA", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledCircle(50, 225, 20);
}

void iDraw() {
	//place your drawing codes here
	iClear();
	if(page == 1){
        draw_frontpage();
	}
	if(mode == 1){
	    if(home_mouse_position == 1)
	    {
		iSetColor(153, 204, 255);
		iText(270, 65, str);
	    }
	    if(home_mouse_position == 2)
	    {
		iSetColor(153, 204, 255);
		iText(820, 65, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
	//if(access == 1)iText(55, 260, "WELCOME");
	iSetColor(255,0,0);
	/*
	if(access == 1){

            iShowBMP(0,0,"homepage.bmp");
            iSetColor(25, 0, 51);
	        iText(400, 600, "HELLO!CREATE YOUR OWN MESS!",GLUT_BITMAP_TIMES_ROMAN_24);
	        iText(250, 100, "USERNAME",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(250,50,720,60);
            iText(800, 100, "PASSWORD",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(800,50,720,60);
            iSetColor(153, 204, 255);
		    iText(255, 55, name_match);
		    iSetColor(153, 204, 255);
	     	iText(805, 55, pass_match);


	     	iSetColor(255,0,0);
            iText(800, 25, "WELCOME", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	*/
    if(access == -1){

            iShowBMP(0,0,"homepage.bmp");
            iSetColor(25, 0, 51);
	        iText(400, 600, "HELLO!CREATE YOUR OWN MESS!",GLUT_BITMAP_TIMES_ROMAN_24);
	        iText(250, 100, "USERNAME",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(250,50,720,60);
            iText(800, 100, "PASSWORD",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(800,50,720,60);
            iSetColor(153, 204, 255);
		    iText(255, 55, name_match);
		    iSetColor(153, 204, 255);
	     	iText(805, 55, pass_match);

	     	iSetColor(255,0,0);
            iText(800, 25, "WRONG PASSWORD!",GLUT_BITMAP_TIMES_ROMAN_24);
    }
	else if(access == 0){

            iShowBMP(0,0,"homepage.bmp");
            iSetColor(25, 0, 51);
	        iText(400, 600, "HELLO!CREATE YOUR OWN MESS!",GLUT_BITMAP_TIMES_ROMAN_24);
	        iText(250, 100, "USERNAME",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(250,50,720,60);
            iText(800, 100, "PASSWORD",GLUT_BITMAP_TIMES_ROMAN_24);
	        iFilledRectangle(800,50,720,60);
            iSetColor(153, 204, 255);
		    iText(255, 55, name_match);
		    iSetColor(153, 204, 255);
	     	iText(805, 55, pass_match);

	     	iSetColor(255,0,0);
            iText(400, 25, "OOPS!YOU AREN'T ASSIGNED AS A MESS MANAGER!",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(page == 2)draw_homepage();
	if(page == 3)draw_options();
	//if(page == 4)draw_feast();
	if(page == 5)draw_time();
    if(page == 6)draw_breakfast();
    if(page == 7)draw_lunch();
    if(page == 9)draw_dinner();
	if(page == 8)show_total_stock();

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		//click_aluvorta(mx, my);

		if(page == 1){
		if(mx >= 250 && mx <= 400 && my >= 50 && my <= 100 && mode == 0)
		{
			mode = 1;
			home_mouse_position = 1;
		}
		if(mx >= 800 && mx <= 1150 && my >= 50 && my <= 100 && mode == 0)
		{
			mode = 1;
			home_mouse_position = 2;
			//read_login();
		}
		if(mx >= 1190 && mx <= 1250 && my >= 15 && my <= 55)
		{
			printf("clicked\n");
			read_login();
		}

		}
		if(page != 1){
		if(mx >= 1250 && mx <= 1324 && my >= 650 && my <= 720){
                page = 8;
                //read_total_stock();
                printf("working");
            }
        if(mx >= 1250 && mx <= 1324 && my >= 0 && my <= 100){
                page = 2;

            }
		}

        if(page == 1){

        }
		if(page == 2){
                read_total_stock();
                click_total_stock(mx,my);
                click_select_menu(mx,my);
		}
		//if(page == 2)click_select_menu(mx,my);
		if(page == 3)click_options(mx,my);
		//if(page == 4)click_feast();
		if(page == 5)click_time(mx,my);
		if(page == 6)click_breakfast(mx,my);
		if(page == 7)click_lunch(mx,my);
		if(page == 9){
                totalstock_store();
                click_dinner(mx,my);
		}
		if(page == 8)show_total_stock();
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
/*
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(key == 's'){
        page = 8;
	}
	//place your codes for other keys here
}
*/
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	iInitialize(1324, 720, "mess managing");
	return 0;
}
