//  逐次版のクイックソート
int Partition (int p, int r)
{
  int x = A[p];
  int k = p;
  int l = r+1;
  int t;

  do k++; while ((A[k] <= x) && (k < r));
  do l--; while (A[l] > x);

  while (k < l) {
    t = A[k]; A[k] = A[l]; A[l] = t;
    do k++; while (A[k] <= x);
    do l--; while (A[l] > x);
  }
  t = A[p]; A[p] = A[l]; A[l] = t;
  return l;
}

void QuickSort(int p, int r)
{
  if (p < r) {
    int q = Partition(p, r);
    QuickSort (p, q-1);
    QuickSort (q+1, r);
  }
}

