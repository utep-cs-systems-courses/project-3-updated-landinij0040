#include "project.h"

static int bitSubtractor = 1;
void color_changes()
{
  if (rowChange <= 130){
    color = color - bitSubtractor;
    bitSubtractor <<= 1;
  }else{
    bitSubtractor = 1; // resetting bit subtractor
  }


}
