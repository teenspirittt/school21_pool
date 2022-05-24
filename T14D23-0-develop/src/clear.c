#include <stdio.h>
#include <stdlib.h>

#include "search.h"
#include "state_sort.h"
int rewrite(FILE *fp, off_t to, off_t from, off_t end) {
  char buf[get_size(fp)];
  int l;

  while (from < end) {
    fseek(fp, from, SEEK_SET);
    l = fread(buf, 1, get_size(fp), fp);
    if (l < 0) return l;
    from += l;
    fseek(fp, to, SEEK_SET);
    if (fwrite(buf, 1, l, fp) != l) return -1;
    to += l;
  }

  return l;
}
