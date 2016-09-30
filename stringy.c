#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  int i = 0;
  for (; s1[i] || s2[i]; i++)
    if (s1[i] != s2[i])
      return s1[i] - s2[i];
}

char * mystrchr(char *s, char c) {
  int i = 0;
  for (; s[i]; i++) {
    if (s[i] - c == 0) {
      return s+i;
    }
  }
  return '\0';
}

char * mystrstr(char *s, char *sub) {
  return 0;
}

int main() {
  return 0;
}
