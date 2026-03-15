#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    char word[1000];
    scanf("%s", word);

    // punepunepune
    // first char = 'p';
    // last char = 'e'
    char first = word[0];
    char last = word[strlen(word)-1];
    int count = strlen(word);
    if(count > 10) {
      // strlen("punepunepune") > 10 then print p10e
      printf("%c%d%c\n", first, count-2, last);
    } else {
      // strlen("pune") < 10 then print pune
      printf("%s\n", word);
    }
  }


  return 0;
}
