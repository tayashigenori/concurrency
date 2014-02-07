unsinged __stdcall QuickSort(LPVOID pArg)
{
  int p, r, q;
  qSortIndex *d = NULL, *d1, *d2;
  long t;
  int N = *((int *) pArg);

  while(1) {
    WaitForSingleObject(hSem, INFINITE);
    if (Done) break; // スレッドを終了させる外部通知
    dequeue(Q, d);
    p = d->lo;
    r = d->hi;
    delete d;
    if (p < r)
    {
      q = Partition(p, r);
      InterlockedIncrement(&tCount);
      d1 = new qSortIndex; d1->lo = p; d1->hi = q-1;
      enqueue(Q, d1);
      d2 = new qSortIndex; d2->lo = q+1; d2->hi = r;
      ReleaseSemaphore(hSem, 2, NULL); //キューへデータを2つ追加したので、セマフォカウンタを2増やす
    }
    else if (p == r) {
      t = InterlockedIncrement(&tCount);
      if (t == N) SetEvent(tSignal); // ソート終了を通知する
    }
  }
  return 0;
}

// QuickSort() を呼び出す部分
e1 = new qSortIndex;
e1->lo = 0; e1->hi = NumToSort -1;
enqueue(Q, e1);

// キューのセマフォカウンタを1で初期化する
hSem = CreateSemaphore(NULL, 1, NumToSort, NULL);

for (i = 0; i < NUM_THREADS; i++)
  hThreads[i] = (HANDLE) _beginthreadex(NULL, 0, QuickSort, &NumToSort, 0, NULL);

WaitForSingleObject(tSignal, INFINITE); // 通知を待つ

Done = TRUE;
ReleaseSemaphore(hSem, NUM_THREADS, NULL);


