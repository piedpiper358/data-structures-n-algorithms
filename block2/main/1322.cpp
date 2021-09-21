#include <stdio.h>
#include <string.h>

size_t i, j;
size_t len;
char s[100000];
int pos;
int vector[100000];
int tmp[100000];

void swap(int a, int b)
{
  int t;

  t = tmp[a]; tmp[a] = tmp[b]; tmp[b] = t;
  t = vector[a]; vector[a] = vector[b]; vector[b] = t;
}

void sort(int beg, int end)
{
  int mid = tmp[beg], l = beg + 1, r = end;
  
  if (end > beg + 1)
  {
    while (l < r)
    {
      if (tmp[l] != mid)
      {
        if (tmp[l] < mid)
          l++;
        else
          swap(l, --r);
      }
      else
      {
        if (vector[l] < vector[beg])
          l++;
        else
          swap(l, --r);
      }
    }
    swap(--l, beg);
    sort(beg, l);
    sort(r, end);
  }
}

int main(int argc, char *argv[])
{
  scanf("%d %s",&pos, s);
  len = strlen(s);

  for (i = 0; i < len; i++)
  {
    tmp[i] = s[i];
    vector[i] = i;
  }
  sort(0, len);

  for (i = 0; i < len; i++)
  {
    tmp[i] = tmp[i] | (s[i] << 8);
    vector[i] = i;
  }
  sort(0, len);

  j = vector[pos - 1];
  for (i = 0; i < len; i++)
  {
    putchar(s[j]);
    j = vector[j];
  }

  return 0;
}