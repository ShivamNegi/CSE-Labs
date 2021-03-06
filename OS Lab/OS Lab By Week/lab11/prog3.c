#include <stdio.h>
#include <stdlib.h>

int* sort(int *a,int n)
{
  int i, j;
  for(i=0; i<=n-1; i++)
    for(j=0; j<=n-i-1; j++)
      if(a[j+1] < a[j])
      {
        int temp = a[j+1];
        a[j+1] = a[j];
        a[j] = temp;
      }
  return a;
}

int search(int *a, int key, int n)
{
  int i=0;
  while(i<n && a[i] != key)
    i++;
  return i;
}

int main()
{
  int n, *queue, head, end;
  int i;
  printf("Enter the size of queue request :\n");
  scanf("%d", &n);
  queue = (int*) calloc(n+1, sizeof(int));
  for(i=1; i<=n; i++)
    scanf("%d", &queue[i]);
  printf("Enter the starting head position:\n");
  scanf("%d", &head);
  printf("Enter the End Position :");
  scanf("%d", &end);
  queue[0] = head;
  queue = sort(queue, n);
  int seek = 0;
  int pos = search(queue, head, n);
  printf("Track Traversed\tDifferent between Tracks\n");
  for(i=pos; i>=1; i--)
  {
    int diff = abs(queue[i]-queue[i-1]);
    seek += diff;
    printf("%d\t\t%d\n", queue[i-1], diff);
  }
  seek += abs(queue[i]-0);
  int start = end-1;
  int k = n;
  while(k>pos)
  {
    int diff = abs(start-queue[k]);
    seek += diff;
    printf("%d\t\t%d\n", queue[k], diff);
    start = queue[k];
    k--;
  }
  double avg = (seek/n);
  printf("Average Seek Time :%.2f\n",avg);
  return 0;
}
