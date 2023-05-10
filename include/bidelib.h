/*************************************************************************
  brian's ide
  Copyright (c) 2023 Brian O'Dell
  
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  This Source Code Form is "Incompatible With Secondary Licenses", as
  defined by the Mozilla Public License, v. 2.0.

*************************************************************************/

#ifndef BIDE_LIB
#define BIDE_LIB

#include "../include/bide.h"

#define ANSIESC     "\x1b["
#define ANSIUP      "A"
#define ANSIDOWN    "B"
#define ANSIRIGHT   "C"
#define ANSILEFT    "D"


extern struct winsize termsize;

char **buffer_addline(char **buffer, char *newline);
char **buffer_removeline(char **buffer, int lineno);

void populate_termsize();
void ansi_clear();
void ansi_home();
void ansi_setfg(int fg);
void ansi_movecursor(int count, const char *dir);



#endif
