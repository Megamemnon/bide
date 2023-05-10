/*************************************************************************
  brian's ide
  Copyright (c) 2023 Brian O'Dell
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  This Source Code Form is "Incompatible With Secondary Licenses", as
  defined by the Mozilla Public License, v. 2.0.

*************************************************************************/

#include "../include/bide.h"
#include "../include/bidelib.h"


void init_screen(){
    populate_termsize();

    ansi_clear();
    ansi_home();
    ansi_setfg(32);
    printf("FILE     EDIT     RUN     ");
    ansi_movecursor(1, ANSIDOWN);
    ansi_movecursor(999, ANSILEFT);
    ansi_setfg(39);
    printf("test\n");
}

char readchar(){
    char ch=0;
    read(STDIN_FILENO, &ch, sizeof(ch));
    return ch;
}

void edit(){
    char ch=0;
    bool cont=true;
    while(cont){
        ch=readchar();
        if(ch!=0){
            if(ch==27){
                ch=readchar();
                if(ch=='['){
                    ch=readchar();
                    switch (ch)
                    {
                    case 'A':
                        /* Up Arrow */
                        break;
                    case 'B':
                        /* Down Arrow */
                        break;
                    case 'C':
                        /* Right Arrow */
                        break;
                    case 'D':
                        /* Left Arrow */
                        break;
                    
                    default:
                        break;
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    static struct termios oldt, newt;
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);

    init_screen();
    char **x=buffer_addline(NULL,"this is line 1");
    x=buffer_addline(x, "this is line 2.");
    edit();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}

