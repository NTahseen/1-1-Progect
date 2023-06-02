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
char ingredients[40][20];  //name of each ingredients
double total_amount[40];   //amount of ingredients in particular index of total array
double d1, d2, d3, d4, d5;
double price[] = {30,40,60,40,60,40,80,40,80,120,350,400,200,250,800,400,800,1000,250,110,10,80,160};
double taka[] = {0};

int vegetables_position;
int spices_position;
int fishes_position;
int meats_position;
int others_position;

int ruti_color_mode = 0;
int nastavaji_color_mode = 0;
int dim_color_mode = 0;
int vaat_color = 0;
int murgi_color = 0;
int daal_color = 0;
int aluvorta_color = 0;
int simvorta_color = 0;
int begunvaji_color = 0;
int shobji_color = 0;
int ruimach_color = 0;
int pabdamach_color = 0;
int pangash_color = 0;
int telapia_color = 0;

void show_total_stock()
{
    //total_stock_page = 1;

    //printf("show total stock\n");

    iClear();

    iShowBMP(0,0,"total_stock_bg.bmp");


	iSetColor(255, 255, 153);
	iFilledRectangle(0,0,265,720);
	iSetColor(153, 204, 255);
	iFilledRectangle(265,0,265,720);
	iSetColor(204, 255, 153);
	iFilledRectangle(530,0,265,720);
	iSetColor(255, 153, 255);
	iFilledRectangle(795,0,265,720);
	iSetColor(224, 224, 224);
	iFilledRectangle(1060,0,265,720);


	iSetColor(255,128, 0);
	iText(50, 590 , "VEGETABLES(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(50,540,100,30);
	iFilledRectangle(50,490,100,30);
	iFilledRectangle(50,440,100,30);
	iFilledRectangle(50,390,100,30);
	iFilledRectangle(50,340,100,30);

	iFilledRectangle(170,540,75,30);
	iFilledRectangle(170,490,75,30);
	iFilledRectangle(170,440,75,30);
	iFilledRectangle(170,390,75,30);
	iFilledRectangle(170,340,75,30);

	iSetColor(102,102, 255);
	iText(325, 590 , "SPICES(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(315,540,100,30);
	iFilledRectangle(315,490,100,30);
	iFilledRectangle(315,440,100,30);
	iFilledRectangle(315,390,100,30);
	iFilledRectangle(315,340,100,30);

	iFilledRectangle(435,540,75,30);
	iFilledRectangle(435,490,75,30);
	iFilledRectangle(435,440,75,30);
	iFilledRectangle(435,390,75,30);
	iFilledRectangle(435,340,75,30);

	iSetColor(0,153, 0);
	//iText(595, 570 , "SPICES(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(595, 590 , "FISHES(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(580,540,120,30);
	iFilledRectangle(580,490,120,30);
	iFilledRectangle(580,440,120,30);
	iFilledRectangle(580,390,120,30);
	iFilledRectangle(580,340,120,30);

	iFilledRectangle(709,540,75,30);
	iFilledRectangle(709,490,75,30);
	iFilledRectangle(709,440,75,30);
	iFilledRectangle(709,390,75,30);
	iFilledRectangle(709,340,75,30);

	iSetColor(153,0, 153);
	//iText(845, 570 , "FISHES(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(845, 590 , "MEATS(KG)" , GLUT_BITMAP_TIMES_ROMAN_24);
	//iFilledRectangle(580,540,100,30);
	iFilledRectangle(835,490,100,30);
	iFilledRectangle(835,440,100,30);
	iFilledRectangle(835,390,100,30);
    //iFilledRectangle(580,340,100,30);

	//iFilledRectangle(700,540,75,30);
	iFilledRectangle(955,490,75,30);
	iFilledRectangle(955,440,75,30);
	iFilledRectangle(955,390,75,30);
    //iFilledRectangle(700,340,75,30);

    iSetColor(96,96, 96);
    iText(1100, 590 , "OTHERS(KG/LITRE)" , GLUT_BITMAP_TIMES_ROMAN_24);

	iFilledRectangle(1110,540,125,30);
	iFilledRectangle(1110,490,125,30);
	iFilledRectangle(1110,440,125,30);
	iFilledRectangle(1110,390,125,30);
	iFilledRectangle(1110,340,125,30);

	iFilledRectangle(1240,540,75,30);
	iFilledRectangle(1240,490,75,30);
	iFilledRectangle(1240,440,75,30);
	iFilledRectangle(1240,390,75,30);
	iFilledRectangle(1240,340,75,30);
	iFilledRectangle(1110, 20,210,30);

    char s[10];
    //printf("%s %lf\n", ingredients[0], total_amount[0]);
    iSetColor(255, 255, 153);
    sprintf(s, "%.2lf", total_amount[0]);
    iText(60, 550 , ingredients[0] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(180, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);


     sprintf(s, "%.2lf", total_amount[1]);
    iText(60, 500 , ingredients[1] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(180, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[2]);
    iText(60, 450 , ingredients[2] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(180, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[3]);
    iText(60, 400 , ingredients[3] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(180, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[4]);
    iText(60, 350 , ingredients[4] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(180, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(153, 204, 255);

    sprintf(s, "%.2lf", total_amount[5]);
    iText(325, 550 , ingredients[5] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(445, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[6]);
    iText(325, 500 , ingredients[6] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(445, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[7]);
    iText(325, 450 , ingredients[7] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(445, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[8]);
    iText(325, 400 , ingredients[8] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(445, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[9]);
    iText(325, 350 , ingredients[9] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(445, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);




    iSetColor(204, 255, 153);
    sprintf(s, "%.2lf", total_amount[10]);
    iText(590, 550 , ingredients[10] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[11]);
    iText(585, 500 , ingredients[11] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[12]);
    iText(590, 450 , ingredients[12] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[13]);
    iText(590, 400 , ingredients[13] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[14]);
    iText(590, 350 , ingredients[14] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(710, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);




    iSetColor(255, 153, 255);
    sprintf(s, "%.2lf", total_amount[15]);
    iText(855, 500 , ingredients[15] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(975, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[16]);
    iText(855, 450 , ingredients[16] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(975, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[17]);
    iText(855, 400 , ingredients[17] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(975, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);



    iSetColor(224, 224, 224);
    sprintf(s, "%.2lf", total_amount[18]);
    iText(1120, 550 , ingredients[18] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1240, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[19]);
    iText(1120, 500 , ingredients[19] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1240, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[20]);
    iText(1120, 450 , ingredients[20] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1240, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[21]);
    iText(1120, 400 , ingredients[21] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1240, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", total_amount[22]);
    iText(1120, 350 , ingredients[22] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1240, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    iText(1120, 25 , "BACK TO HOMEPAGE" , GLUT_BITMAP_HELVETICA_18);

}

void draw_expenditure1(){
     char s[10];

    iShowBMP(0,0,"expenditureblue.bmp");

    iSetColor(204,229,255);
    iText(560, 590, "VEGETABLES(TAKA)", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(540, 545, 120, 30);
	iFilledRectangle(540, 495, 120, 30);
	iFilledRectangle(540, 445, 120, 30);
	iFilledRectangle(540, 395, 120, 30);
	iFilledRectangle(540, 345, 120, 30);

	iFilledRectangle(710, 545, 75, 30);
	iFilledRectangle(710, 495, 75, 30);
	iFilledRectangle(710, 445, 75, 30);
	iFilledRectangle(710, 395, 75, 30);
	iFilledRectangle(710, 345, 75, 30);

	iText(640, 260 , "BACK" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0,0,102);

    sprintf(s, "%.2lf", taka[0]);
    iText(550, 550 , ingredients[0] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);


     sprintf(s, "%.2lf", taka[1]);
    iText(550, 500 , ingredients[1] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[2]);
    iText(550, 450 , ingredients[2] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[3]);
    iText(550, 400 , ingredients[3] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[4]);
    iText(550, 350 , ingredients[4] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);



}

void draw_expenditure2(){
     char s[10];

     iShowBMP(0,0,"expenditureblue.bmp");

    iSetColor(204,229,255);
    iText(580, 590, "SPICES(TAKA)", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(540, 545, 120, 30);
	iFilledRectangle(540, 495, 120, 30);
	iFilledRectangle(540, 445, 120, 30);
	iFilledRectangle(540, 395, 120, 30);
	iFilledRectangle(540, 345, 120, 30);

	iFilledRectangle(710, 545, 75, 30);
	iFilledRectangle(710, 495, 75, 30);
	iFilledRectangle(710, 445, 75, 30);
	iFilledRectangle(710, 395, 75, 30);
	iFilledRectangle(710, 345, 75, 30);

	iSetColor(204,229,255);
	iText(640, 260 , "BACK" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0,0,102);

    sprintf(s, "%.2lf", taka[5]);
    iText(550, 550 , ingredients[5] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

     sprintf(s, "%.2lf", taka[6]);
    iText(550, 500 , ingredients[6] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[7]);
    iText(550, 450 , ingredients[7] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[8]);
    iText(550, 400 , ingredients[8] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[9]);
    iText(550, 350 , ingredients[9] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);



}

void draw_expenditure3(){
     char s[10];

     iShowBMP(0,0,"expenditureblue.bmp");

    iSetColor(204,229,255);
    iText(560, 590, "FISHES(TAKA)", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(540, 545, 120, 30);
	iFilledRectangle(540, 495, 120, 30);
	iFilledRectangle(540, 445, 120, 30);
	iFilledRectangle(540, 395, 120, 30);
	iFilledRectangle(540, 345, 120, 30);

	iFilledRectangle(710, 545, 75, 30);
	iFilledRectangle(710, 495, 75, 30);
	iFilledRectangle(710, 445, 75, 30);
	iFilledRectangle(710, 395, 75, 30);
	iFilledRectangle(710, 345, 75, 30);

	iText(640, 260 , "BACK" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0,0,102);


     sprintf(s, "%.2lf", taka[10]);
    iText(550, 550 , ingredients[10] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

     sprintf(s, "%.2lf", taka[11]);
     printf("%s\n", ingredients[11]);
    iText(550, 500 , ingredients[11] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[12]);
    iText(550, 450 , ingredients[12] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[13]);
    iText(550, 400 , ingredients[13] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[14]);
    iText(550, 350 , ingredients[14] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);


}


void draw_expenditure4(){
     char s[7];
     //printf("ghdfjhfd\n");

     iShowBMP(0,0,"expenditureblue.bmp");

    iSetColor(204,229,255);
    iText(560, 590, "MEATS(TAKA)", GLUT_BITMAP_TIMES_ROMAN_24);
	//iFilledRectangle(540, 545, 120, 30);
	iFilledRectangle(540, 495, 120, 30);
	iFilledRectangle(540, 445, 120, 30);
	iFilledRectangle(540, 395, 120, 30);
	//iFilledRectangle(540, 345, 120, 30);

	//iFilledRectangle(710, 545, 75, 30);
	iFilledRectangle(710, 495, 75, 30);
	iFilledRectangle(710, 445, 75, 30);
	iFilledRectangle(710, 395, 75, 30);
	//iFilledRectangle(710, 345, 75, 30);

	iText(640, 260 , "BACK" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0,0,102);

     sprintf(s, "%.2lf", taka[15]);
    iText(550, 500 , ingredients[15] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    printf("%s %lf\n", ingredients[15], taka[15]);


    //ingredients[16] = "goru";
    strcpy(ingredients[16], "goru");
    taka[16] = 0;
    sprintf(s, "%.2lf", taka[16]);
    iText(550, 450 , ingredients[16] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);


    sprintf(s, "%.2lf", taka[17]);
    iText(550, 400 , ingredients[17] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);




}

void draw_expenditure5(){
     char s[10];

     iShowBMP(0,0,"expenditureblue.bmp");

    iSetColor(204,229,255);
    iText(560, 590, "OTHERS(TAKA)", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(540, 545, 120, 30);
	iFilledRectangle(540, 495, 120, 30);
	iFilledRectangle(540, 445, 120, 30);
	iFilledRectangle(540, 395, 120, 30);
	iFilledRectangle(540, 345, 120, 30);

	iFilledRectangle(710, 545, 75, 30);
	iFilledRectangle(710, 495, 75, 30);
	iFilledRectangle(710, 445, 75, 30);
	iFilledRectangle(710, 395, 75, 30);
	iFilledRectangle(710, 345, 75, 30);

	iText(640, 260 , "BACK" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0,0,102);

    sprintf(s, "%.2lf", taka[18]);
    iText(543, 550 , ingredients[18] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 550 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    taka[19] = 55.00;
     sprintf(s, "%.2lf", taka[19]);
    iText(550, 500 , ingredients[19] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 500 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[20]);
    iText(550, 450 , ingredients[20] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 450 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[21]);
    iText(550, 400 , ingredients[21] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 400 , s , GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(s, "%.2lf", taka[22]);
    iText(550, 350 , ingredients[22] , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 350 , s , GLUT_BITMAP_TIMES_ROMAN_24);



}


void draw_expenditure_option()
{
	iClear();
	iSetColor(160, 160, 160);
	iShowBMP(0, 0, "add_items2.bmp");

	iFilledRectangle(550, 62, 300, 40);
	iFilledRectangle(550, 206, 300, 40);
	iFilledRectangle(550, 350, 300, 40);
	iFilledRectangle(550, 494, 300, 40);
	iFilledRectangle(550, 638, 300, 40);

	iText(1120, 25, "BACK TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);

	iSetColor(0, 0, 102);
	iText(640, 72, "OTHERS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(650, 216, "MEATS", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640, 360, "FISHES", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640, 504, "SPICES", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(620, 648, "VEGETABLES", GLUT_BITMAP_TIMES_ROMAN_24);
}

void click_expenditure(int mx, int my){
	if (mx >= 550 && mx <= 850 && my >= 62 && my <= 102)
		page = 21;
	if (mx >= 550 && mx <= 850 && my >= 206 && my <= 246){
		page = 20;
	}
	if (mx >= 550 && mx <= 850 && my >= 350 && my <= 390)
		page = 19;
	if (mx >= 550 && mx <= 850 && my >= 494 && my <= 534)
		page = 18;
	if (mx >= 550 && mx <= 850 && my >= 638 && my <= 678)
		page = 17;
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
        printf("file opened\n");
    }
    while(!feof(ptr)){

    printf("%d %s\n", i, *ptr);
        fscanf(ptr, "%s", &ingredients[i]);
        fscanf(ptr, "%lf", &total_amount[i]);
        i++;
    }

    for(int i = 0; total_amount[i]!='\0'; i++){
        printf("hello     %s %g\n", ingredients[i], total_amount[i]);
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
    printf("%d stock page\n", page);
    for(int i = 0; i < total_amount[i] != '\0'; i++){
        printf("click total stock %s ", ingredients[i]);
        printf("%g\n", total_amount[i]);
    }
}


void totalstock_store()
{
    int i = 0;
    FILE *ptr;
    ptr = fopen("total_stock.txt", "r");
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

void update_totalstock()
{
    int i = 0;
    FILE *ptr;
    ptr = fopen("total_stock.txt", "w");
    if(ptr == NULL){
        printf("total_stock file cant be open\n");
        return;
    }
    //else printf("aluvorta opened\n");

    for(int i = 0; i < 23; i++){
        fprintf(ptr, "%s %g\n", ingredients[i], total_amount[i]);

    }

}

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
	iShowBMP(0,0,"pagee2_bg.bmp");
	iShowBMP(440,80,"chef.bmp");
	iSetColor(255, 255, 204);
    iText(525, 270, "HELLO", GLUT_BITMAP_TIMES_ROMAN_24);
    //printf("%s", name_match);
    iText(520, 220, name_match, GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP(130,180,"add_item.bmp");
	iShowBMP(130,470,"total_stock.bmp");
	iShowBMP(1090,470,"select_menu.bmp");
	iShowBMP(1090,180,"expenditure.bmp");

	iSetColor(102, 0, 102);
     iFilledRectangle(90,390,230,40);
     iFilledRectangle(90,100,230,40);
     iFilledRectangle(1060,390,230,40);
     iFilledRectangle(1060,100,230,40);

	iSetColor(204, 229, 255);
	iText(100, 400, "TOTAL STOCK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(110, 110, "ADD ITEMS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1070, 400, "SELECT MEALS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1070, 110, "EXPENDITURE", GLUT_BITMAP_TIMES_ROMAN_24);


}

void click_homepage(int mx, int my)
{
    if(mx >= 1070 && mx <= 2100 && my >= 400 && my <= 450){
        page = 3;
    }
    if(mx >= 1070 && mx <= 2100 && my >= 110 && my <= 150){
    page = 16;
    }
    if(mx >= 100 && mx <= 150 && my >= 400 && my <= 450){
    page = 8;
    }
    if(mx >= 100 && mx <= 150 && my >= 110 && my <= 150){
    page = 10;
    }
}

void draw_materials()
{
    iClear();
	iSetColor(160, 160, 160);
	iShowBMP(0,0,"total_stock_bg.bmp");

	iSetColor(0, 0, 102);
    iFilledRectangle(550,62,300,40);
    iFilledRectangle(550,206,300,40);
    iFilledRectangle(550,350,300,40);
    iFilledRectangle(550,494,300,40);
    iFilledRectangle(550,638,300,40);


    iSetColor(204, 204, 255);
    iText(640, 72, "OTHERS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(650, 216, "MEATS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(640, 360, "FISHES", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(640, 504, "SPICES", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(620, 648, "VEGETABLES", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0, 0, 102);
    iFilledRectangle(1090,20,230,25);
    iFilledRectangle(1090,690,190,25);
    iSetColor(204, 204, 255);
    iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
    iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);


}

void click_materials(int mx, int my){
    if(mx >= 550 && mx <= 850 && my >= 62 && my <= 102)
    page = 15;
    if(mx >= 550 && mx <= 850 && my >= 206 && my <= 246)
    page = 14;
    if(mx >= 550 && mx <= 850 && my >= 350 && my <= 390)
    page = 13;
    if(mx >= 550 && mx <= 850 && my >= 494 && my <= 534)
    page = 12;
    if(mx >= 550 && mx <= 850 && my >= 638 && my <= 678)
    page = 11;
}


void draw_vegetables()
{
    iClear();
     iShowBMP(0,0,"add_items2.bmp");
	iSetColor(160, 160, 160);
    iFilledRectangle(680,62,100,40);
    iFilledRectangle(680,206,100,40);
    iFilledRectangle(680,350,100,40);
    iFilledRectangle(680,494,100,40);
    iFilledRectangle(680,638,100,40);
    iFilledRectangle(900,350,130,40);

    iSetColor(192, 192, 192);
    iText(550, 72, "ALU", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 216, "SIM", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 360, "BEGUN", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 504, "TOMATO", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 648, "GAJOR", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(650, 690, "AMOUNT IN KG", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 51);
    iText(915, 360, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(160, 160, 160);
    iFilledRectangle(640,20,90,30);
    iFilledRectangle(1090,690,190,25);
    iSetColor(0, 0, 51);
    iText(650, 27, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1099, 700, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);

    iSetColor(160,160,160);
    iFilledRectangle(1090,20,230,25);
    iSetColor(0,0,51);
    iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);


}


void draw_spices()
{
    iClear();
    iShowBMP(0,0,"add_items2.bmp");
	iSetColor(160, 160, 160);
    iFilledRectangle(680,62,100,40);
    iFilledRectangle(680,206,100,40);
    iFilledRectangle(680,350,100,40);
    iFilledRectangle(680,494,100,40);
    iFilledRectangle(680,638,100,40);
    iFilledRectangle(900,350,130,40);

    iSetColor(192, 192, 192);
    iText(550, 72, "PEYAJ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 216, "MORICH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 360, "LOBON", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 504, "ADA", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 648, "ROSHUN", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(650, 690, "AMOUNT IN KG", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 51);
    iText(915, 360, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(160, 160, 160);
    iFilledRectangle(640,20,90,30);
    iFilledRectangle(1090,690,190,25);
    iSetColor(0, 0, 51);
    iText(650, 27, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1099, 700, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
}

void draw_fishes()
{
    iClear();
     iShowBMP(0,0,"add_items2.bmp");
	iSetColor(160, 160, 160);
    iFilledRectangle(700,62,100,40);
    iFilledRectangle(700,206,100,40);
    iFilledRectangle(700,350,100,40);
    iFilledRectangle(700,494,100,40);
    iFilledRectangle(700,638,100,40);
    iFilledRectangle(900,350,130,40);

    iSetColor(192, 192, 192);
    iText(550, 72, "RUI MACH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 216, "PABDA", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 360, "PANGASH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 504, "TELAPIA", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 648, "ILISH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 690, "AMOUNT IN NUMBERS", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 51);
    iText(915, 360, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(160, 160, 160);
    iFilledRectangle(640,20,90,30);
    iFilledRectangle(1090,690,190,25);
    iSetColor(0, 0, 51);
    iText(650, 27, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1099, 700, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
}

void draw_meats()
{
    iClear();
    iShowBMP(0,0,"add_items2.bmp");
	iSetColor(160, 160, 160);
    //iFilledRectangle(700,62,100,40);
    iFilledRectangle(700,206,100,40);
    iFilledRectangle(700,350,100,40);
    iFilledRectangle(700,494,100,40);
    iFilledRectangle(900,350,130,40);
    //iFilledRectangle(700,638,100,40);

    iSetColor(192, 192, 192);
    //iText(550, 72, "MURGI", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 216, "MURGI", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 360, "GORU", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 504, "KHASHI", GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(550, 648, "ROSHUN", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 690, "AMOUNT IN KG", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 51);
    iText(915, 360, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(160, 160, 160);
    iFilledRectangle(640,20,90,30);
    iFilledRectangle(1090,690,190,25);
    iSetColor(0, 0, 51);
    iText(650, 27, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1099, 700, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
}


void draw_others()
{
    iClear();
    iShowBMP(0,0,"add_items2.bmp");
	iSetColor(160, 160, 160);
    iFilledRectangle(700,62,100,40);
    iFilledRectangle(700,206,100,40);
    iFilledRectangle(700,350,100,40);
    iFilledRectangle(700,494,100,40);
    iFilledRectangle(700,638,100,40);
    iFilledRectangle(900,350,130,40);

    iSetColor(192, 192, 192);
    iText(500, 72, "SORISHAR TEL", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(500, 216, "ATA", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(500, 360, "DIM(EGG)", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(500, 504, "CHAAL", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(500, 648, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(650, 690, "AMOUNT IN KG/LITRE", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0, 0, 51);
    iText(915, 360, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(160, 160, 160);
    iFilledRectangle(640,20,90,30);
    iFilledRectangle(1090,690,190,25);
    iSetColor(0, 0, 51);
    iText(650, 27, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1099, 700, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
}


void click_vegetables(int mx, int my)
{
    if(mx >= 680 && mx <= 780 && my >= 62 && my <= 102 && mode == 0)
		{
		    vegetables_position = 1;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 206 && my <= 246 && mode == 0)
		{
		    vegetables_position = 2;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 350 && my <= 390 && mode == 0)
		{
		    vegetables_position = 3;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 494 && my <= 534 && mode == 0)
		{
		    vegetables_position = 4;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 638 && my <= 678 && mode == 0)
		{
		    vegetables_position = 5;
			mode = 1;
		}
    if(mx >= 900 && mx <= 1130 && my >= 350 && my <= 390){
            update_totalstock();
            for(int i = 0; i < 23; i++){
                printf("%s %g\n", ingredients[i], total_amount[i]);
            }
        }
}

void click_spices(int mx, int my)
{
    if(mx >= 680 && mx <= 780 && my >= 62 && my <= 102 && mode == 0)
		{
		    spices_position = 1;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 206 && my <= 246 && mode == 0)
		{
		    spices_position = 2;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 350 && my <= 390 && mode == 0)
		{
		    spices_position = 3;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 494 && my <= 534 && mode == 0)
		{
		    spices_position = 4;
			mode = 1;
		}
    if(mx >= 680 && mx <= 780 && my >= 638 && my <= 678 && mode == 0)
		{
		    spices_position = 5;
			mode = 1;
		}
    if(mx >= 900 && mx <= 1130 && my >= 350 && my <= 390){
            update_totalstock();
            for(int i = 0; i < 23; i++){
                printf("%s %g\n", ingredients[i], total_amount[i]);
            }
        }
}

void click_fishes(int mx, int my)
{
    if(mx >= 700 && mx <= 800 && my >= 62 && my <= 102 && mode == 0)
		{
		    fishes_position = 1;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 206 && my <= 246 && mode == 0)
		{
		    fishes_position = 2;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 350 && my <= 390 && mode == 0)
		{
		    fishes_position = 3;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 494 && my <= 534 && mode == 0)
		{
		    fishes_position = 4;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 638 && my <= 678 && mode == 0)
		{
		    fishes_position = 5;
			mode = 1;
		}
    if(mx >= 900 && mx <= 1130 && my >= 350 && my <= 390){
            update_totalstock();
            for(int i = 0; i < 23; i++){
                printf("%s %g\n", ingredients[i], total_amount[i]);
            }
        }
}

void click_meats(int mx, int my)
{
    if(mx >= 700 && mx <= 800 && my >= 62 && my <= 102 && mode == 0)
		{
		    meats_position = 1;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 206 && my <= 246 && mode == 0)
		{
		    meats_position = 2;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 350 && my <= 390 && mode == 0)
		{
		    meats_position = 3;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 494 && my <= 534 && mode == 0)
		{
		    meats_position = 4;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 638 && my <= 678 && mode == 0)
		{
		    meats_position = 5;
			mode = 1;
		}
    if(mx >= 900 && mx <= 1130 && my >= 350 && my <= 390){
            update_totalstock();
            for(int i = 0; i < 23; i++){
                printf("%s %g\n", ingredients[i], total_amount[i]);
            }
        }
}

void click_others(int mx, int my)
{
    if(mx >= 700 && mx <= 800 && my >= 62 && my <= 102 && mode == 0)
		{
		    others_position = 1;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 206 && my <= 246 && mode == 0)
		{
		    others_position = 2;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 350 && my <= 390 && mode == 0)
		{
		    others_position = 3;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 494 && my <= 534 && mode == 0)
		{
		    others_position = 4;
			mode = 1;
		}
    if(mx >= 700 && mx <= 800 && my >= 638 && my <= 678 && mode == 0)
		{
		    others_position = 5;
			mode = 1;
		}
    if(mx >= 900 && mx <= 1130 && my >= 350 && my <= 390){
            update_totalstock();
            for(int i = 0; i < 23; i++){
                printf("%s %g\n", ingredients[i], total_amount[i]);
            }
        }
}

void draw_veg_options() {

	if(mode == 1){
	    if(vegetables_position == 1)
	    {
		iSetColor(0, 0, 51);
		iText(690, 72, str);
	    }
	    if(vegetables_position == 2)
	    {
		iSetColor(0, 0, 51);
		iText(690, 216, str);
	    }
	    if(vegetables_position == 3)
	    {
		iSetColor(0, 0, 51);
		iText(690, 360, str);
	    }
	    if(vegetables_position == 4)
	    {
		iSetColor(0, 0, 51);
		iText(690, 504, str);
	    }
	    if(vegetables_position == 5)
	    {
		iSetColor(0, 0, 51);
		iText(690, 648, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
}

void draw_spices_options() {

	if(mode == 1){
	    if(spices_position == 1)
	    {
		iSetColor(0, 0, 51);
		iText(690, 72, str);
	    }
	    if(spices_position == 2)
	    {
		iSetColor(0, 0, 51);
		iText(690, 216, str);
	    }
	    if(spices_position == 3)
	    {
		iSetColor(0, 0, 51);
		iText(690, 360, str);
	    }
	    if(spices_position == 4)
	    {
		iSetColor(0, 0, 51);
		iText(690, 504, str);
	    }
	    if(spices_position == 5)
	    {
		iSetColor(0, 0, 51);
		iText(690, 648, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
}

void draw_fishes_options() {

	if(mode == 1){
	    if(fishes_position == 1)
	    {
		iSetColor(0, 0, 51);
		iText(710, 72, str);
	    }
	    if(fishes_position == 2)
	    {
		iSetColor(0, 0, 51);
		iText(710, 216, str);
	    }
	    if(fishes_position == 3)
	    {
		iSetColor(0, 0, 51);
		iText(710, 360, str);
	    }
	    if(fishes_position == 4)
	    {
		iSetColor(0, 0, 51);
		iText(710, 504, str);
	    }
	    if(fishes_position == 5)
	    {
		iSetColor(0, 0, 51);
		iText(710, 648, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
}

void draw_meats_options() {

	if(mode == 1){
	    if(meats_position == 1)
	    {
		iSetColor(0, 0, 51);
		iText(710, 72, str);
	    }
	    if(meats_position == 2)
	    {
		iSetColor(0, 0, 51);
		iText(710, 216, str);
	    }
	    if(meats_position == 3)
	    {
		iSetColor(0, 0, 51);
		iText(710, 360, str);
	    }
	    if(meats_position == 4)
	    {
		iSetColor(0, 0, 51);
		iText(710, 504, str);
	    }
	    if(meats_position == 5)
	    {
		iSetColor(0, 0, 51);
		iText(710, 648, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
}


void draw_others_options() {

	if(mode == 1){
	    if(others_position == 1)
	    {
		iSetColor(0, 0, 51);
		iText(710, 72, str);
	    }
	    if(others_position == 2)
	    {
		iSetColor(0, 0, 51);
		iText(710, 216, str);
	    }
	    if(others_position == 3)
	    {
		iSetColor(0, 0, 51);
		iText(710, 360, str);
	    }
	    if(others_position == 4)
	    {
		iSetColor(0, 0, 51);
		iText(710, 504, str);
	    }
	    if(others_position == 5)
	    {
		iSetColor(0, 0, 51);
		iText(710, 648, str);
	    }

	//iText(10, 10, "Click to activate the box, enter to finish.");
	}
}

void draw_options()
{
    iSetColor(255,255,255);
    iFilledRectangle(0,0,1324,720);

    iShowBMP(0,0,"corner1.bmp");

    iShowBMP(250,10,"menu2.bmp");

    iSetColor(255, 255, 204);

    //iFilledRectangle(590,440,100,30);
    iFilledRectangle(590,190,140,30);

    iSetColor(204,229,255);
    iText(500,600,"BOARDERS NUMBER?",GLUT_BITMAP_TIMES_ROMAN_24);
    iRectangle(550,535, 150, 40);

    iSetColor(0,0,0);
    //iText(600, 450, "FEAST", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 200, "REGULAR", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0, 0, 102);
    iFilledRectangle(1090,20,230,25);
    iFilledRectangle(1090,690,190,25);
    iSetColor(204, 204, 255);
    iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
    iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
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
     if(mx >= 720 && mx <= 800 && my >= 80 && my <= 100 && page==5){
    page = 3;
    }
     printf("click time after %d\n",page);

}

void draw_time()
{

    iClear();

    iSetColor(255,255,255);
    iFilledRectangle(0,0,1324,720);

    iShowBMP(0,0,"corner1.bmp");

    iShowBMP(250,10,"menu2.bmp");

    iSetColor(255, 255, 204);

    iText(600, 430, "BREAKFAST", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 330, "LUNCH", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600, 230, "DINNER", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(720, 80, "BACK", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0, 0, 102);
    iFilledRectangle(1090,20,230,25);
    iFilledRectangle(1090,690,190,25);
    iSetColor(204, 204, 255);
    iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
    iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);

}





int aluvorta(int person)
{
    int x;

    for(int i = 0; i < 20; i++){
        x = strcmp("alu", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[0] += .05*person*price[0];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += .01*person*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            taka[6] += person*.005*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[18] += person*.001*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
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
            taka[1] += person*.05*price[1];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += person*.01*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            taka[6] += person*.005*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[18] += person*.001*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
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
            taka[2] += person*.05*price[2];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += person*.01*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            taka[6] += person*.005*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sorishartel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[18] += person*.001*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
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
            taka[19] += person*.05*price[19];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[7] += person*.01*price[7];
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
            taka[20] += person*1*price[20];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[7] += person*.01*price[7];
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
            taka[8] += person*.05*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tomato", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[3] += person*.05*price[3];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("gajor", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[4] += person*.05*price[4];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[1] += person*.05*price[1];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += person*.01*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            taka[6] += person*.005*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[18] += person*.001*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
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
            taka[0] += person*.05*price[0];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tomato", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[3] += person*.05*price[3];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("gajor", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[4] += person*.05*price[4];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("sim", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.05;
            taka[1] += person*.05*price[1];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += person*.01*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.005;
            taka[6] += person*.005*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[18] += person*.001*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
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
            taka[15] += person*.25*price[15];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[18] += person*.03*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[6] += person*.03*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[5] += person*.03*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[8] += person*.03*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[9] += person*.03*price[9];
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
            taka[10] += person*.25*price[10];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[18] += person*.03*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[6] += person*.03*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[5] += person*.03*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[8] += person*.03*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[9] += person*.03*price[9];
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
            taka[11] += person*.25*price[11];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[18] += person*.03*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[6] += person*.03*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[5] += person*.03*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[8] += person*.03*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[9] += person*.03*price[9];
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
        x = strcmp("pabdamach", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            taka[11] += person*.25*price[11];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[18] += person*.03*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[6] += person*.03*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[5] += person*.03*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[8] += person*.03*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[9] += person*.03*price[9];
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
        x = strcmp("telapia", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.25; // 1 murgi will serve 3 persons
            taka[13] += person*.25*price[13];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[18] += person*.03*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[6] += person*.03*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[5] += person*.03*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.001;
            taka[7] += person*.001*price[7];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("ada", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[8] += person*.03*price[8];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("roshun", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.03;
            taka[9] += person*.03*price[9];
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
            taka[21] += person*.25*price[21];
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
        x = strcmp("daal", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.1;
            taka[22] += person*.1*price[22];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("peyaj", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[5] += person*.01*price[5];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("morich", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[6] += person*.01*price[6];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("tel", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[18] += person*.01*price[18];
            if(total_amount[i] < 0) return -1;
        }
        x = strcmp("lobon", ingredients[i]);
        if(x == 0){
            total_amount[i] = total_amount[i] - person*.01;
            taka[7] += person*.01*price[7];
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
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620){
        //update_ruti();
        ruti_color_mode = 1;
        printf("ruti %d %d %d\n", ruti_color_mode, nastavaji_color_mode, dim_color_mode);
    }
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540){
        //update_nastavaji();
        nastavaji_color_mode = 1;
        //nastavaji_color_mode = 1;
        printf("vaji %d %d %d\n", ruti_color_mode, nastavaji_color_mode, dim_color_mode);
    }
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490){
        //update_dim();
        dim_color_mode = 1;
        printf("dim %d %d %d\n", ruti_color_mode, nastavaji_color_mode, dim_color_mode);
    }
    if(mx >= 20 && mx <= 85 && my >= 20 && my <= 40){
        page = 5;
    }
    if(mx >= 80 && mx <= 200 && my >= 350 && my <= 370){
        update_ruti();
        update_nastavaji();
        update_dim();
        ruti_color_mode = 0;
        nastavaji_color_mode = 0;
        dim_color_mode = 0;
    }



}

void draw_breakfast(){
    iClear();

    iShowBMP(0,0,"last_bg_left.bmp");
    iShowBMP(400,0,"last_bg.bmp");
    iShowBMP(1120,0,"last_bg_left.bmp");

    iSetColor(153,204,255);
	iFilledRectangle(75,575,100,30);
	iFilledRectangle(75,495,100,30);
	iFilledRectangle(75,445,100,30);

	iSetColor(0, 0, 51);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 580, "RUTI", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 500, "VAJI", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 450, "DIM", GLUT_BITMAP_TIMES_ROMAN_24);


	if(ruti_color_mode == 1){
        iSetColor(0, 128, 255);
        iFilledRectangle(75,575,100,30);
        iSetColor(0, 0, 51);
	    iText(80, 580, "RUTI", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(nastavaji_color_mode == 1){
        iSetColor(0, 128, 255);
        iFilledRectangle(75,495,100,30);
        iSetColor(0, 0, 51);
	    iText(80, 500, "VAJI", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(dim_color_mode == 1){
        iSetColor(0, 128, 255);
        iFilledRectangle(75,445,100,30);
        iSetColor(0, 0, 51);
	    iText(80, 450, "DIM", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	iText(80, 350, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(153,204,255);
	iFilledRectangle(1090, 20, 230, 25);
	iFilledRectangle(1090, 690, 190, 25);
	iFilledRectangle(20,20,65,20);
	iSetColor(0, 0, 102);
	iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
	iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
	iText(25, 25, "BACK", GLUT_BITMAP_HELVETICA_18);

}



void click_dinner(int mx, int my){
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620){
    vaat_color = 1;
    }
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540){
    murgi_color = 1;
    }
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490){
    daal_color = 1;
    }
    if(mx >= 80 && mx <= 140 && my >= 370 && my <= 410){
    aluvorta_color = 1;
    }
    if(mx >= 80 && mx <= 140 && my >= 320 && my <= 360){
    simvorta_color = 1;
    }
    if(mx >= 80 && mx <= 140 && my >= 270 && my <= 310){
    begunvaji_color = 1;
    }

    if (mx >= 20 && mx <= 85 && my >= 20 && my <= 40){
		page = 5;
	}

	if (mx >= 80 && mx <= 200 && my >= 200 && my <= 230){
		update_vaat();
		update_murgi();
        update_daal();
        update_aluvorta();
        update_simvorta();
        update_begunvaji();
        vaat_color = 0;
        murgi_color = 0;
        daal_color = 0;
        aluvorta_color = 0;
        simvorta_color = 0;
        begunvaji_color = 0;
	}

}


void draw_dinner(){
    iClear();

    iShowBMP(0, 0, "last_bg_left.bmp");
	iShowBMP(400, 0, "last_bg.bmp");
	iShowBMP(1120, 0, "last_bg_left.bmp");

	iSetColor(153, 204, 255);
	iFilledRectangle(75, 575, 180, 30);
	iFilledRectangle(75, 495, 180, 30);
	iFilledRectangle(75, 445, 180, 30);
	iFilledRectangle(75, 365, 180, 30);
	iFilledRectangle(75, 315, 180, 30);
	iFilledRectangle(75, 265, 180, 30);

	iSetColor(0, 0, 51);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 500, "CHICKEN", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 450, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 370, "ALU VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 320, "SIM VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 270, "BEGUN VAJI", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 200, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

	if (vaat_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 575, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (murgi_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 495, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 500, "CHICKEN", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (daal_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 445, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 450, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (aluvorta_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 365, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 370, "ALU VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (simvorta_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 315, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 320, "SIM VORTA", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (begunvaji_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 265, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 270, "BEGUN VAJI", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//iText(80, 350, "SEE EXPENDITURE FOR THESE", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(153, 204, 255);
	iFilledRectangle(1090, 20, 230, 25);
	iFilledRectangle(1090, 690, 190, 25);
	iFilledRectangle(20, 20, 65, 20);
	iSetColor(0, 0, 102);
	iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
	iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
	iText(25, 25, "BACK", GLUT_BITMAP_HELVETICA_18);

}

void click_lunch(int mx, int my){
    if(mx >= 80 && mx <= 140 && my >= 580 && my <= 620)
    vaat_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 500 && my <= 540)
    daal_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 450 && my <= 490)
    shobji_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 370 && my <= 410)
    ruimach_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 320 && my <= 360)
    pabdamach_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 270 && my <= 310)
    pangash_color = 1;
    if(mx >= 80 && mx <= 140 && my >= 220 && my <= 260)
    telapia_color = 1;

    if (mx >= 20 && mx <= 85 && my >= 20 && my <= 40){
		page = 5;
	}

	if (mx >= 80 && mx <= 200 && my >= 170 && my <= 200){
		update_vaat();
		update_murgi();
		update_daal();
		update_shobji();
		update_ruimach();
		update_pabdamach();
		update_pangash();
		update_telapia();
		vaat_color = 0;
		murgi_color = 0;
		daal_color = 0;
		shobji_color = 0;
		ruimach_color = 0;
		pabdamach_color = 0;
		pangash_color = 0;
		telapia_color = 0;
	}


}


void draw_lunch(){
    iClear();
	iShowBMP(0, 0, "last_bg_left.bmp");
	iShowBMP(400, 0, "last_bg.bmp");
	iShowBMP(1120, 0, "last_bg_left.bmp");

	iSetColor(153, 204, 255);
	iFilledRectangle(75, 575, 180, 30);
	iFilledRectangle(75, 495, 180, 30);
	iFilledRectangle(75, 445, 180, 30);
	iFilledRectangle(75, 365, 180, 30);
	iFilledRectangle(75, 315, 180, 30);
	iFilledRectangle(75, 265, 180, 30);
	iFilledRectangle(75, 215, 180, 30);

	iSetColor(0, 0, 51);
	iText(80, 650, "SELECT ITEMS : ", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 500, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 450, "SHOBJI", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 370, "RUI MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 320, "PABDA MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 270, "PANGASH", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(80, 220, "TELAPIA", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(80, 170, "UPDATE", GLUT_BITMAP_TIMES_ROMAN_24);

	if (vaat_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 575, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 580, "VAAT", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (daal_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 495, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 500, "DAAL", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (shobji_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 445, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 450, "SHOBJI", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (ruimach_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 365, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 370, "RUI MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (pabdamach_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 315, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 320, "PABDA MACHH", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (pangash_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 265, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 270, "PANGASH", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (telapia_color == 1){
		iSetColor(0, 128, 255);
		iFilledRectangle(75, 215, 180, 30);
		iSetColor(0, 0, 51);
		iText(80, 220, "TELAPIA", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	iSetColor(153, 204, 255);
	iFilledRectangle(1090, 20, 230, 25);
	iFilledRectangle(1090, 690, 190, 25);
	iFilledRectangle(20, 20, 65, 20);
	iSetColor(0, 0, 102);
	iText(1100, 25, "GO TO HOMEPAGE", GLUT_BITMAP_HELVETICA_18);
	iText(1099, 693, "SEE TOTAL STOCK", GLUT_BITMAP_HELVETICA_18);
	iText(25, 25, "BACK", GLUT_BITMAP_HELVETICA_18);



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

            if(page == 3){
                person = atoi(str);
            }

            printf("yeeeeeeeeeeee person %s %d\n", str, person);
            if(page == 11){

                int d = atoi(str);
                /*
                printf("%lf", 1.0*d);
                update_vegetables(1.0*d);
                */
                if(vegetables_position == 1){
                    total_amount[0] += 1.0*d;  //alu
                }

                if(vegetables_position == 2){
                    total_amount[1] += 1.0*d;  //sim
                }

                if(vegetables_position == 3){
                    total_amount[2] += 1.0*d;  //begun
                }

                if(vegetables_position == 4){
                    total_amount[3] += 1.0*d;  //tomato
                }

                if(vegetables_position == 5){
                    total_amount[4] += 1.0*d;  //gajor
                }
            }

             if(page == 12){

                int d = atoi(str);
                /*
                printf("%lf", 1.0*d);
                update_vegetables(1.0*d);
                */
                if(spices_position == 1){
                    total_amount[5] += 1.0*d;  //peyaj
                }

                if(spices_position == 2){
                    total_amount[6] += 1.0*d;  //morich
                }

                if(spices_position == 3){
                    total_amount[7] += 1.0*d;  //lobon

                }

                if(spices_position == 4){
                    total_amount[8] += 1.0*d;  //ada

                }

                if(spices_position == 5){
                    total_amount[9] += 1.0*d;  //roshun
                }
            }


             if(page == 13){

                int d = atoi(str);
                /*
                printf("%lf", 1.0*d);
                update_vegetables(1.0*d);
                */
                if(fishes_position == 1){
                    total_amount[10] += 1.0*d;  //rui
                }

                if(fishes_position == 2){
                    total_amount[11] += 1.0*d;  //pabda
                }

                if(fishes_position == 3){
                    total_amount[12] += 1.0*d;  //pangash

                }

                if(fishes_position == 4){
                    total_amount[13] += 1.0*d;  //telapia

                }

                if(fishes_position == 5){
                    total_amount[14] += 1.0*d;  //ilish
                }
            }

            if(page == 14){

                int d = atoi(str);
                /*
                printf("%lf", 1.0*d);
                update_vegetables(1.0*d);
                */
                /*
                if(fishes_position == 1){
                    total_amount[10] += 1.0*d;  //rui
                }

                */
                if(meats_position == 2){
                    total_amount[15] += 1.0*d;  //murgi
                }

                if(meats_position == 3){
                    total_amount[16] += 1.0*d;  //goru

                }

                if(meats_position == 4){
                    total_amount[17] += 1.0*d;  //khashi

                }

                /*
                if(fishes_position == 5){
                    total_amount[14] += 1.0*d;  //ilish
                }
                */
            }

            if(page == 15){

                int d = atoi(str);
                /*
                printf("%lf", 1.0*d);
                update_vegetables(1.0*d);
                */
                if(others_position == 1){
                    total_amount[18] += 1.0*d;  //shorishartel
                }

                if(others_position == 2){
                    total_amount[19] += 1.0*d;  //ata
                }

                if(others_position == 3){
                    total_amount[20] += 1.0*d;  //dim

                }

                if(others_position == 4){
                    total_amount[21] += 1.0*d;  //chaal

                }

                if(others_position == 5){
                    total_amount[22] += 1.0*d;  //daal
                }
            }

           // printf("%s %s\n", name_match, pass_match);
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

void iDraw() {
	//place your drawing codes here
	iClear();

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

	if(page == 2)draw_homepage();
	if(page == 3){
            draw_options();
            if(mode == 1){
                iText(600,550,str);
            }
	}
	//if(page == 4)draw_feast();
	if(page == 5)draw_time();
    if(page == 6)draw_breakfast();
    if(page == 7)draw_lunch();
    if(page == 9)draw_dinner();

	if(page == 8)show_total_stock();

	if(page == 10)draw_materials();
	if(page == 11){
        draw_vegetables();
	    if(mode == 1)draw_veg_options();
	}
	if(page == 12){
        draw_spices();
	    if(mode == 1)draw_spices_options();
	}
	if(page == 13){
        draw_fishes();
	    if(mode == 1)draw_fishes_options();
	}
	if(page == 14){
        draw_meats();
	    if(mode == 1)draw_meats_options();
	}
	if(page == 15){
        draw_others();
	    if(mode == 1)draw_others_options();
	}
	if(page == 16){
        draw_expenditure_option();
        //draw_expenditure2();
	    if(mode == 1)draw_others_options();
	}
	if(page == 17){
        draw_expenditure1();
	}
	if(page == 18){
        draw_expenditure2();
	}
	if(page == 19){
        draw_expenditure3();
	}
	if(page == 20){
        draw_expenditure4();
	}
	if(page == 21){
        draw_expenditure5();
	}
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

		/*
		if(page == 2){
                read_total_stock();
                click_total_stock(mx,my);
               // click_select_menu(mx,my);
		}
		*/

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
			page = 2;
			//read_login();
		}

		}

		if(page != 1){
		if(mx >= 1250 && mx <= 1324 && my >= 650 && my <= 720){
                page = 8;

                read_total_stock();
                printf("working");
            }
		}
		if(mx >= 1250 && mx <= 1324 && my >= 0 && my <= 100){
                page = 2;

            }
		if(page == 2){
                read_total_stock();
                click_homepage(mx,my);

		}
		if(page == 3){
            click_options(mx,my);
            if (mx >= 550 && mx <= 700 && my >= 535 && my <= 575 && mode == 0)
			{
				mode = 1;
			}
		}
		//if(page == 4)click_feast();
		if(page == 5)click_time(mx,my);
		if(page == 6)click_breakfast(mx,my);
		if(page == 7)click_lunch(mx,my);
		if(page == 9){
                totalstock_store();
                click_dinner(mx,my);
		}

		if(page == 8){
            read_total_stock();
            show_total_stock();
		}

		//if(page == 2)click_select_menu(mx,my);
		if(page == 10){
            read_total_stock();
            click_materials(mx,my);

		}
		if(page == 11){
            click_vegetables(mx,my);

		}
		if(page == 12){
            click_spices(mx,my);
		}
		if(page == 13){
            click_fishes(mx,my);
		}
		if(page == 14){
            click_meats(mx,my);
		}
		if(page == 15){
            click_others(mx,my);
		}
		if(page == 16){
            click_expenditure(mx,my);
		}
		if(page == 17 || page == 18 || page == 19 || page == 20|| page == 21){
            if(mx >= 440 && mx <= 1324 && my >= 260 && my <= 300){
                page = 16;

            }
		}
		if(page == 11 || page == 12 || page == 13 || page == 14|| page == 15){
            if(mx >= 650 && mx <= 720 && my >= 27 && my <= 40){
                page = 10;

            }
		}

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



























