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

int countPairs3(int *arr, int len, int value) { return 0; }
