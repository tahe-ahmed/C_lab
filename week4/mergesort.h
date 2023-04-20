
template <typename T> void Merge(std::vector<T> &numbers, int i, int j, int k) {
  int mergedSize; 
  int mergePos;  
  int leftPos;   
  int rightPos;  

  mergePos = 0;
  mergedSize = k - i + 1;
  leftPos = i;     
  rightPos = j + 1; 
  std::vector<T> mergedNumbers(mergedSize); 

  while (leftPos <= j && rightPos <= k) {
    if (numbers[leftPos] < numbers[rightPos]) {
      mergedNumbers.at(mergePos) = numbers.at(leftPos);
      ++leftPos;
    } else {
      mergedNumbers.at(mergePos) = numbers.at(rightPos);
      ++rightPos;
    }
    ++mergePos;
  }

  while (leftPos <= j) {
    mergedNumbers.at(mergePos) = numbers.at(leftPos);
    ++leftPos;
    ++mergePos;
  }

  while (rightPos <= k) {
    mergedNumbers.at(mergePos) = numbers.at(rightPos);
    ++rightPos;
    ++mergePos;
  }

  for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
    numbers.at(i + mergePos) = mergedNumbers.at(mergePos);
  }
};

template <typename T>
void mergeSort(std::vector<T> &data, unsigned int firstToSort,
               unsigned int lastToSort) {
  int j;

  if (firstToSort < lastToSort) {
    j = (firstToSort + lastToSort) / 2; 

    mergeSort(data, firstToSort, j);
    mergeSort(data, j + 1, lastToSort);

    Merge(data, firstToSort, j, lastToSort);
  }
};