#include <stdio.h>
#include <iostream>
using namespace std;
//Using Pointers to Print 2D Arrays
//traditionally:
   // for(int i=0; i<row; i++) {
   //    for(int j=0; j<col; j++) {
   //       printf("%d", a[i][j]);
   //    }
   // }
//using pointers
   //  for(p = &a[0][0]; p <= &a[row-1][col-1]; p++) {
   //                      //&a[1][1]
   //      printf("%d ", *p);
   //      //output: 1         2       3           4
   //      //       a[0][0]  a[0][1]   a[1][0]    a[1][1]
   //  }
