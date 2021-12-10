#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){
  mkfifo("toC", 0644);
  mkfifo("toP", 0644);

  int toP = open("fds0", O_RDONLY);
  int toC = open("fds1", O_WRONLY);

  char buffer[1000];
  while(1){
    printf("input: \n");
    fgets(buffer, sizeof(buffer), stdin);
    write(toC, buffer, sizeof(buffer));
    read(toP, buffer, sizeof(buffer));
    printf("processed input: %s\n\n", buffer);
  }

  return 0;
}
