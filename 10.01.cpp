// Sorted Merge LCCI
#include <iostream>
#include <vector>

using namespace std;
//
class Solution
{
public:
// 先合并，在排序
  void merge1(vector<int> &A, int m, vector<int> &B, int n)
  {
    for (int i = m; i < m+n; i++)
    {
        A[i] = B[i - m];
    }
    sort(A.begin(), A.end());
  }
  //使用双指针，一个指针指向A数组的最后，一个指针指向B数组的最后，比较指向的两个值的大小，将大的值插入
  void merge2(vector<int> &A, int m, vector<int> &B, int n)
  {
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    while (i >= 0 && j >= 0)
    {
      if (A[i] >= B[j])
      {
        A[index--] = A[i--];
      }
      else
      {
        A[index--] = B[j--];
      }
    }
    while (i >= 0)
    {
      A[index--] = A[i--];
    }
    while (j >= 0)
    {
      A[index--] = B[j--];
    }
  }
};