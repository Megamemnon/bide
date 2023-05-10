/*************************************************************************
  brian's ide
  Copyright (c) 2023 Brian O'Dell
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  This Source Code Form is "Incompatible With Secondary Licenses", as
  defined by the Mozilla Public License, v. 2.0.

*************************************************************************/

#include "../include/bidelib.h"

struct winsize termsize;
int termRow, termCol;

#pragma region Edit Buffer

char **buffer_addline(char **buffer, char *newline){
    if(!buffer){
        buffer = GC_malloc(sizeof(char *));
        buffer[0]=newline;
    } else {
        int size = sizeof(buffer)/sizeof(*buffer);
        size+=1;
        char **b=buffer;
        buffer=GC_malloc(sizeof(char *) * (size));
        for(int i=0; i<size-1;i++){
            buffer[i]=b[i];
        }
        buffer[size-1]=newline;
    }
    return buffer;
}

char **buffer_removeline(char **buffer, int lineno){
    int size = sizeof(buffer)/sizeof(*buffer) - 1;
    if(size==0) return NULL;
    char **b=buffer;
    buffer=GC_malloc(sizeof(char *) * size);
    for(int i=0; i<size; i++){
        if(i<lineno){
            buffer[i]=b[i];
        } else {
            buffer[i]=b[i+1];
        }
    }
    return buffer;
}

#pragma endregion

#pragma region ANSI Codes

void populate_termsize(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ ,&termsize);
}

void ansi_clear(){
    printf("%s2J", ANSIESC);
}

void ansi_home(){
    printf("%sH", ANSIESC);
}

void ansi_setfg(int fg){
    char buffer[11];
    sprintf(buffer, "%d", fg);
    printf("%s0;%sm", ANSIESC, buffer);
}

void ansi_movecursor(int count, const char *dir){
    char buffer[11];
    sprintf(buffer, "%d", count);
    printf("%s%s%s", ANSIESC, buffer, dir);
}

#pragma endregion