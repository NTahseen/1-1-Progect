# include "iGraphics.h"
#include<stdio.h>
#include<string.h>

int x = 500, y = 500;

//homepage variables
int page = 1;
int mode = 0;
int len = 0;
char str[100];
char name_match[100];
char pass_match[100];
char name[100][40];
char password[100][40];
int home_mouse_position = 1;


void draw_homepage()
{
    iSetColor(153, 255, 51);
	iText(x/3, 9*y/10, "Hello!Create Your Mess",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 104);
	iText(x/4, 7*y/10, "Username",GLUT_BITMAP_HELVETICA_18);
	iRectangle(x/4,5*y/10,x/2,y/12);
	iText(x/4, 3*y/10, "Password",GLUT_BITMAP_HELVETICA_18);
	iRectangle(x/4,1*y/10,x/2,y/12);
	iSetColor(20, 200, 0);

}

void iDraw() {
	iClear();
	if(page == 1){
        draw_homepage();
	}
	if(mode == 1){
	    if(home_mouse_position == 1)
	    {
		iSetColor(255, 255, 255);
		iText(55, 260, str);
	    }
	    if(home_mouse_position == 2)
	    {
		iSetColor(255, 255, 255);
		iText(95, 100, str);
	    }

	iText(10, 10, "Click to activate the box, enter to finish.");
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

//for homepage
void login_info();
void read_login();
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(page == 1){
		if(mx >= x/4 && mx <= x/2 && my >= y/2 && my <= 7*y/12 && mode == 0)
		{
			mode = 1;
			printf("a");
			home_mouse_position = 1;
		}
		if(mx >= x/4 && mx <= x/2 && my >= y/10 && my <= 11*y/60 && mode == 0)
		{
		    //read_login();
			mode = 1;
			home_mouse_position = 2;
			//read_login();
		}
		if(mx >= 400 && mx <= 500 && my >= 0 && my <= 500)
		{
		    //read_login();
		    printf("clociked\n");
			//mode = 1;
			//home_mouse_position = 2;
			//read_login();
		}

		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void login_test();

void read_login()
{
    printf("read login func called\n");
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


    for(int j = 0; name[j]!='\0'; j++){
        printf("%s %s\n",name[i], password[i]);
    }


    login_test();
}

void login_test()
{
    printf("login text func called\n");
   /* char ch[30], pass_match[20];
    FILE *ptr=fopen("login.txt","r");
    if(ptr == NULL){
        printf("login file can't be opened\n");
        return;
    }
    */

    printf("yes\n");
   

    for(int i = 0; name[i]!='\0'; i++){
        int x = strcmp(name_match, name[i]);
        int y = strcmp(pass_match, password[i]);

        if(x == 0 && y == 0){
                printf("elcome\n");
            iText(40, 40, "Welcome", GLUT_BITMAP_TIMES_ROMAN_24);
             page = 2;
             break;
        }
        else if(x == 0 && y != 0){
            iText(40, 40, "password incorret!!", GLUT_BITMAP_TIMES_ROMAN_24);
            printf("incorrect\n");
        }
        else {
            iText(40, 40, "Wrong", GLUT_BITMAP_TIMES_ROMAN_24);
            printf("wrong\n");
        }

    }

    //printf("%d\n", home_x);


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
            if(home_mouse_position == 1)strcpy(name_match,str);
            if(home_mouse_position == 2){
                    strcpy(pass_match, str);
                    //read_login();
                    //login_test();
            }
            //if(home_mouse_position == 1)strcpy(home_user,s1);
            //if(home_mouse_position == 2)strcpy(home_pass,s1);

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
	iInitialize(500, 500, "mess managing");

	return 0;
}
