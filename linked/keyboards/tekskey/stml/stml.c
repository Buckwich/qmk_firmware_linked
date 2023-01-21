

#include "rgb_matrix.h"

 
 led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {  0, 1, 2, NO_LED, 3, 4 },
  { 10, 9, 8, 7, 6, 5 },
  { 11,12,13,14,15,16 },
  { 22,21,20,19,18,17 },
  { 23,24,25,26,27,28 },
  { 34,33,32,31,30,29 }
}, {
  // LED Index to Physical Position
{ 0, 0 },{ 45, 0 },{ 112, 0 },{ 157, 0 },{ 224, 0 },
{ 224, 13 },{ 179, 13 },{ 134, 13 },{ 90, 13 },{ 45, 13 },{ 0, 13 },
{ 0, 26 },{ 45, 26 },{ 90, 26 },{ 134, 26 },{ 179, 26 },{ 224, 26 },
{ 224, 38 },{ 179, 38 },{ 134, 38 },{ 90, 38 },{ 45, 38 },{ 0, 38 },
{ 0, 51 },{ 45, 51 },{ 90, 51 },{ 134, 51 },{ 179, 51 },{ 224, 51 },
{ 224, 64 },{ 179, 64 },{ 134, 64 },{ 90, 64 },{ 45, 64 },{ 0, 64 }
}, {
  // LED Index to Flag
  4,4,4,4,4,
  4,4,4,4,4,4,  
  4,4,4,4,4,4,    
  4,4,4,4,4,4,     
  4,4,4,4,4,4,     
  4,4,4,4,4,4
}
};