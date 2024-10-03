
#include <stdio.h>

typedef struct {
   char m:3;
   char n:5;
   short s;
    
   union {
      int a;
      char b;
   };
    
   int h;
} __attribute__((packed)) data_t;

int main() {
  data_t m;
  printf("%lu\n", sizeof(m));  // Note: %lu for size_t type
  return 0;
}
