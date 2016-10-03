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
  if (sub == "") return s;
  
  int i;
  int subLen = mystrlen(sub);
  for (i = 0; s[i]; s++) {
    int j = 0;
    for (; j < subLen; j++) {
      if ((s[j] == sub[j]) && (j == subLen-1))
	return s;
      else if (s[j] != sub[j])
	break;
    }
  }
  return '\0';
  
}

int main() {
  printf("Before applying functions:\n");
  char s1[] = "Hello-World";
  char s2[50] = "";
  char s3[] = "Happy-Birthday";
  printf("s1 = %s\tlength = %d\n", s1, mystrlen(s1));
  printf("s2 = %s\t\t\tlength = %d\n", s2, mystrlen(s2));
  printf("s3 = %s\tlength = %d\n", s3, mystrlen(s3));

  printf("\nTesting regular functions:\n");
  mystrcpy(s2,s1);
  printf("Copy s1 to s2:\t\ts2 = %s\tlength = %d\n", s2, mystrlen(s2));
  mystrcat(s2, "-War");
  printf("Cat \"-War\" to s2:\ts2 = %s\tlength = %d\n", s2, mystrlen(s2));

  printf("\nTesting \"n\" functions:\n");
  mystrncpy(s2, s3, 4);
  printf("Copy 4 characters of s3 to s2:\t\ts2 = %s\t\tlength = %d\n", s2, mystrlen(s2));
  mystrncat(s2, "123456", 3);
  printf("Cat 3 characters of \"123456\" to s2:\ts2 = %s\t\tlength = %d\n", s2, mystrlen(s2));

  printf("\nTesting cmp:\n");
  printf("Compare ab to abc: %d\n", mystrcmp("ab","abc"));
  printf("Compare abc to ab: %d\n", mystrcmp("abc","ab"));
  printf("Compare abc to abc: %d\n", mystrcmp("abc","abc"));

  printf("\nTesting chr:\n");
  char s4[] = "It's not a bug, it's a feature";
  printf("Original string: \"%s\"\n", s4);
  printf("Looking for 'a': \"%s\"\n", mystrchr(s4, 'a'));
  printf("Lookinf for 'f': \"%s\"\n", mystrchr(s4, 'f'));
  printf("Looking for 'z': \"%s\"\n", mystrchr(s4, 'z'));
  
  printf("\nTesting str:\n");
  char s5[] = "The C language combines all the power of assembly language with all the ease-of-use of assembly language";
  printf("Original string: \"%s\"\n", s5);
  printf("Looking for \"assembly\": \"%s\"\n", mystrstr(s5, "assembly"));
  printf("Looking for \"ease\": \"%s\"\n", mystrstr(s5, "ease"));
  printf("Looking for \"java\": \"%s\"\n", mystrstr(s5, "java"));

}
