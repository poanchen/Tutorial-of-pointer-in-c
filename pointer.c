#include <stdlib.h>

int main(int argc, char *argv[]) {

  /*
  *	A character
  *
  * ---- ----
  * |f | |\0|
  * ---- ----
  * a
  */

  //char----------

  char a = 'f';

  //printf("%c\n", a); //prints f



  /*----------------------------------*/



  /*
  *	A string or an array contains characters
  *
  * ---- ---- ----
  * |f | |s | |\0|
  * ---- ---- ----
  * *b   *++b *(b+=2)
  * b[0] b[1] b[2]
  *
  * b = fs
  */

  //char*---------

  char* b = (char*) malloc (sizeof(char)*3);
  b = "fs";

  //printf("%s\n", b); //prints fs
  //printf("%c\n", b[1]); //prints s
  //printf("%c\n", *b); //prints f



  /*----------------------------------*/



  /*
  *	An array contains string or 2D array contains character or string array
  *
  * ------- ------- -------
  * |abd\0| |efg\0| |\0 	|
  * ------- ------- -------
  * *c      *(++c)  *(c+=2)
  * c[0]    c[1]    c[2]
  *
  * *c[0]     = **c      = c[0][0] = a
  * *c[1]     = *(++*c)  = c[0][1] = b
  * *c[2]     = *(*c+=2) = c[0][2] = d
  * *(++c)[0] = *(*c+=4) = c[1][0] = e
  * *(++c)[1] = *(*c+=5) = c[1][1] = f
  * *(++c)[2] = *(*c+=6) = c[1][2] = g
  */

  //char**--------

  char** c = (char**) malloc (sizeof(char*)*3);
  *c = "abd";
  *(++c) = "efg";

  //printf("%s\n", *(--c)); //prints abd
  //printf("%s\n", *(++c)); //prints efg
  //printf("%c\n", *(--c)[0]); //prints a



  /*----------------------------------*/



  /*
  *	An array contains (an array contains string or string array) or 2D array contains string
  *   (array inside the array)
  *
  * --------------------------- ---------------------------
  * | ------- ------- ------- | | ------- ------- ------- |
  * | |ghi\0| |jkl\0| |\0   | | | |     | |     | |     | |
  * | ------- ------- ------- | | ------- ------- ------- | 
  * --------------------------- ---------------------------
  *
  * **d     = *d[0]     = d[0][0] = ghi
  * *(++*d) = (++*d)[0] = d[0][1] = jkl
  *
  * ***d      = **d[0]      = d[0][0][0] = g
  * *(++**d)  = (++**d)[0]  = d[0][0][1] = h
  * *(**d+=2) = (**d+=2)[0] = d[0][0][2] = i
  * *(**d+=4) = (**d+=4)[0] = d[0][0][2] = j
  * *(**d+=5) = (**d+=5)[0] = d[0][0][2] = k
  * *(**d+=6) = (**d+=6)[0] = d[0][0][2] = l
  */

  //char***-------

  char*** d = (char***) malloc (sizeof(char**)*2);
  char** e = (char**) malloc (sizeof(char*)*3);

  *d = e;
  *e = "ghi";
  *(++e) = "jkl";

  //printf("%s\n", **d); //prints ghi
  //printf("%c\n", ***d); //prints g
  //printf("%s\n", &***d); //prints ghi

  //char***-------

  return 0;
}