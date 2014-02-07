// 再帰を使った版のクイックソート
unsigned __stdcall QuickSort(qSortIndex *m)
{
  int p = m->lo;
  int r = m->hi;
  if (p < r)
  {
    qSortIndex s, t;
    HANDLE tH[2];
    int q = Partition(p, r);
    s.lo = p; s.hi = q-1;
    tH[0] = (HANDLE)_beginthreadex (NULL, 0, QuickSort, &s, 0, NULL);
    t.lo = q+1; t.hi = r;
    tH[1] = (HANDLE)_beginthreadex (NULL, 0, QuickSort, &t, 0, NULL);
    WaitForMultipleObjects(2, tH, TRUE, INFINITE);
  }
  return 0;
}

