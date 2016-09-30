#include <stdlib.h>
#include <stdio.h>


int mystrlen(char *s) {
  int i = 0;
  while (*s) {
    s++;
    i++;
  }
  return i;
}

char * mystrcpy( char *dest, char *source ) {
  int i = 0;
  for (; source[i]; i++)
    dest[i] = source[i];
  dest[i] = '\0';
  return dest;
}

char * mystrncpy(char *dest, char *source, int n) {
  int i = 0;
  for (; source[i] && i < n; i++)
    dest[i] = source[i];
  for (; i < n; i++) // fill in rem bytes with 0
    dest[i] = '\0';
  return dest; 
}

char * mystrcat(char *dest, char *source) {
  int i = 0;
  int destLen = mystrlen(dest);
  for (; source[i]; i++) 
    dest[destLen + i] = source[i];
    
  dest[destLen + i] = '\0';
  return dest;
}

char * mystrncat(char *dest, char *source, int n) {
  int i = 0;
  int destLen = mystrlen(dest);
  for (; source[i] && i < n; i++)
    dest[destLen + i] = source[i];
  
  dest[destLen + i] = '\0';
  return dest;

}

int mystrcmp(char *s1, char *s2) {
  return 0;
}

char * mystrchr(char *s, char c) {
  return 0;
}

int main() {
  char source[] = "World";
  char dest[100] = "Hello";
  printf("%s\n", mystrcpy(dest,source));
  return 0;
}
