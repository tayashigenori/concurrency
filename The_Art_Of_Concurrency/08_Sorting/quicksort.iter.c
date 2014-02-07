// 繰り返しを使った版のクイックソート
void QuickSort(LPVOID pArg)
{
  int p, r, q;
  qSortIndex *d = NULL, *d1, *d2;

  while (notEmpty(Q)) {
    dequeue(Q, d); //次のインデックスペアを取り出す
    p = d->lo;
    r = d->hi;
    delete d;

    if (p < r) { // データが存在した場合
      q = Partition(p, r);

      // 前方のパーティションを表す2つのインデックスをカプセル化して enqueue する
      d1 = new qSortIndex;
      d1->lo = p;
      d2->hi = q-1;
      enqueue(Q, d1);

      // 後方のパーティションを表す2つのインデックスをカプセル化して enqueue する
      d2 = new qSortIndex;
      d2->lo = q+1;
      d2->hi = r;
      enqueue(Q, d2);
    }
  }
}

