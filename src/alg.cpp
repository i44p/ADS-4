// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value) count++;
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i >= value) continue;
    for (int j = i + 1; j < len; j++) {
      int s = arr[i] + arr[j];
      if (s == value) {
        count++;
        continue;
      }
      if (s > value) break;
    }
  }
  return count;
}

int search_leftmost(int *arr, int value, int left, int right) {
  if (left > right) {
    return left;
  }

  if (arr[left] == value) return left;

  int cursor = (left + right) / 2;

  if (arr[cursor] < value) {
    return search_leftmost(arr, value, cursor + 1, right);
  }
  return search_leftmost(arr, value, left, cursor - 1);
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int j = search_leftmost(arr, value - arr[i], i, len - 1);
    while (arr[j] + arr[i] == value) {
      j++;
      count++;
    }
  }
  return count;
}
