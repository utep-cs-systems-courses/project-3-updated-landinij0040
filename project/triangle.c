#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include <p2switches.h>
#include "project.h"
#include "triangle.h"

/**
 * \param col is the colomn of the triangle's downward point
 * \param row is the row of the triangle's downward point
 * \param height is the height of the triangle
 */
void down_triangle(u_char col, u_char row, u_char height){
  int acrossColumns;     // Amount to move accross both sides
  int amountToCross = 0; // Amount to move accross according to the iteration
  int upRow;             // Amount to subtract row
  for (upRow = 0; upRow < height; upRow++){
    amountToCross++;
    for(int i = 0; i < amountToCross; i++){
      drawPixel(col + i , row - upRow , 0xffff);
      drawPixel(col - i , row - upRow , 0xffff);
    }
  }
}


/**
 * \param col is the colomn of the triangle's upward point
 * \param row is the row of the triangle's upward point
 * \param height is the height of the triangle
 */
void up_triangle(u_char col, u_char row, u_char height){
  int acrossColumns;     // Amount to move accross both sides
  int amountToCross = 0; // Amount to move accross according to the iteration
  int upRow;             // Amount to subtract row
  for (upRow = 0; upRow < height; upRow++){
    amountToCross++;
    for(int i = 0; i < amountToCross; i++){
      drawPixel(col + i , row + upRow , 0xffff);
      drawPixel(col - i , row + upRow , 0xffff);
    }
  }
}
