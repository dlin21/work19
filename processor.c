#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void reverse(char *str);

int main(){
  int toP = open("fds0", O_WRONLY);
  int toC = open("fds1", O_RDONLY);

  char buffer[1000];
  while(1){
    int i = read(toC, buffer, sizeof(buffer));
    buffer[i] = 0;
    reverse(buffer);
    
    write(toP, buffer, sizeof(buffer));
  }
  return 0;
}

void reverse(char *str){
  int len = strlen(str);
  int i, temp;
  for(i=0; i<len/2; i++){
    temp = str[len-i-1];
    str[len-i-1] = str[i];
    str[i] = temp;
  }
}
