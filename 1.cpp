#include <iostream>

class Array{
private:
  int *A;
  int size;
  int length;
  void swap(int *a, int *b){
  int temp{*a};
  *a = *b;
  *b = temp;
  };
public:
  Array(){
    int n;
    std::cout << "Enter size of an array: ";
    std::cin >> size;
    A = new int[size];
    std::cout << "Enter no.of items to be placed: ";
    std::cin >> n;
    std::cout << "Enter the items: ";
    for(int i{0}; i < n; i++){
      std::cin >> A[i];
    } 
    length = n;
  }
  ~Array(){
    delete []A;
  }
  void display();
  void add(int y);
  void insert(int i, int y);
  int delete_item(int i);
  int linear_search(int key);
  int binary_Search(int key);
  int recursive_binary_search(int l, int h, int key);
  int get(int i);
  void set(int i, int key);
  int max();
  int min();
  int sum();
  double avg();
  void reverse();
  void Reverse();
  void left_shift();
  void left_rotate();
  void right_shift();
  void right_rotate();
  void insert_inSort(int y);
  int isSorted();
  void reArrange();
  Array* merge(Array *y);
  Array* Union(Array *y);
  Array* Intersection(Array *y);
  Array* difference(Array *y);
  Array* unsorted_union(Array *y);
  Array* unsorted_Intersection(Array *y);
  Array* unsorted_difference(Array *y);
  void missing_element();
  void duplicate();
  void hash_duplicate();
  void duplicate_count();
  void max_and_min();
  void sum_pair(int k);
  void unsorted_duplicates();
  void unsorted_hash_duplicates();
  void unsorted_sum_pair(int k);
  void sum_pair_unsorted_hash(int k);
};

void Array::sum_pair_unsorted_hash(int k){
  int max_item = max();
  int H[max_item + 1];
  for(int i{0}; i < length - 1; i++){
    if(k - A[i] >= 0 && H[k - A[i]] != 0){
      std::cout << A[i] << " + " << k - A[i] << " = " << k << std::endl;
    }
    H[A[i]]++;
  }
}

void Array::unsorted_sum_pair(int k){
  for(int i{0}; i < length - 1; i++){
    for(int j{i+1}; j < length; j++){
      if(A[i] + A[j] == k){
        std::cout << A[i] << " + " << A[j] << " = " << k << std::endl;
      }
    }
  }
}

void Array::unsorted_hash_duplicates(){
  int max_element{max()};
  int H[max_element + 1]{0};
  for(int i{}; i < length; i++){
    H[A[i]]++;
  }
  for(int j{}; j < max_element; j++){
    if(H[j] > 1){
      std::cout << j << " repeated " << H[j] << std::endl;
    }
  }
}

void Array::unsorted_duplicates(){
  for(int i{0}; i < length - 1 ; i++){
    int count{1};
    if(A[i] != -1){
      for(int j{i+1}; j < length; j++){
        if(A[i] == A[j]){
          count++;
          A[j] = -1;
        }
        if(count > 1){
          std::cout << A[i] << " " << count << std::endl;
        }
      }
    }
  }
};

void Array::sum_pair(int k){
  int i{0}, j{length - 1};
  while (i < j){
    if(A[i] + A[j] == k){
      std::cout << A[i] << " + " << A[j] << " = " << k << std::endl;
      i++;
      j--;
    }
    else if(A[i] + A[j] < k){
      i++;
    }else{
      j--;
    }
  }
}

void Array::max_and_min(){
  int min{A[0]}, max{A[0]};
  for(int i{1}; i < length; i++){
    if(A[i] < min){
      min = A[i];
    }else if(A[i] > max){
      max = A[i];
    }
  }
  std::cout << "max and min are " << max <<" " << min << std:: endl;
}

void Array::hash_duplicate(){
  int H[A[length - 1]]{};
  for(int i{0}; i < length; i++){
    H[A[i]]++;
  }
  for(int i{0}; i < A[length - 1]; i++){
    if(H[i] > 1){
      std::cout << i << " and it is repeating " << H[i] << " times" << std::endl;
    }
  }

}

void Array::duplicate_count(){
  for(int i{}; i < length - 1; i++){
    if(A[i] = A[i+1]){
      int j{i+1};
      while (A[j] == A[i])j++;
      std::cout << A[i] << " is appearing " << j - i << " times" << std::endl;
      i = j - 1;
    }
  }
}

void Array::duplicate(){
  int last_duplicate{};
  for(int i{0}; i < length - 1; i++){
    if(A[i] == A[i+1] && A[i] != last_duplicate){
      std::cout << A[i] << std::endl;
      last_duplicate = A[i];
    }
  }
}

void Array::missing_element(){
  // int l {A[length - 1]};
  // int our_sum = (l * (l + 1)) / 2;
  // int s = sum();
  // std::cout << our_sum - s << std::endl;
  int l{A[0]}, h{A[length - 1]}, n{length}, diff{l - 0};
  for(int i{}; i < n; i++){
    if((A[i] - i) != diff){
      while(diff < A[i] - i){
        std::cout << i + diff << std::endl;
        diff++;
      }
    }
  } 
}

// Array* Array::unsorted_union(Array *y){
// }

// Array* Array::unsorted_Intersection(Array *y){

// }

// Array* Array::unsorted_difference(Array *y){

// }

void Array::display(){
  std::cout << "**********************" << std::endl;
  for(int i{0}; i < length; i++){
    if(i != length - 1)
      std::cout << A[i] << " ";
    else
      std::cout << A[i] << std::endl;
  }
  std::cout << "**********************" << std::endl;
}

void Array::add(int y){
  if(length < size){
    A[length] = y;
    length++;
  }
}

void Array::insert(int i, int y){
  if(i>=0 && i <= length && size > length){
    for(int j{length}; j > i; j--){
      A[j] = A[j-1];
    }
    A[i] = y;
    length++;
  }
}

int Array::delete_item(int i){
  int deleted_item{};
  if(i>=0 && i < length){
    deleted_item = A[i];
    for(int j{i}; j < length - 1; j++){
      A[j] = A[j + 1];
    }
  }
  length--;
  return deleted_item;
}

int Array::linear_search(int key){
  for(size_t i{}; i < length; i++){
    if(A[i] == key){
      swap(&(A[i]), &(A[0]));
      return i;
    }
  }
  return -1;
}

int Array::binary_Search(int key){
  int l{}, h{length - 1}, mid{};
  while (l <= h){
    mid = (l+h)/2;
    if(key == A[mid]){
      return mid;
    }
    else if(key < A[mid]){
      h = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return - 1;
}

int Array::recursive_binary_search(int l, int h, int key){
  int mid{};
  while (l <= h){
    mid = (l+h)/2;
    if(key == A[mid]){
      return mid;
    } else if(key < A[mid]){
      return recursive_binary_search(l, mid - 1, key);
    }else{
      return recursive_binary_search(mid + 1, h, key);
    }
  }
  return -1;
}

int Array::get(int i){
  if(i >= 0 and i < length){
    return A[i];
  }
  return -1;
}

void Array::set(int i, int key){
  if(i>=0 and i < length){
    A[i] = key;
  }else
    std::cout << "Wrong index" << std::endl;
}

int Array::max(){
  int max{A[0]};
  for(int i{1}; i < length; i++){
    if(max < A[i]){
      max = A[i];
    }
  }
  return max;
}

int Array::min(){
  int min{A[0]};
  for(int i{1}; i < length; i++){
    if(min > A[i]){
      min = A[i];
    }
  }
  return min;
}

int Array::sum(){
  int sum{};
  for(size_t i{}; i < length; i++){
    sum += A[i];
  }
  return sum;
}

double Array::avg(){
  return static_cast<double>(sum())/length;
}

void Array::reverse(){
  int *B;
  B = new int[length];
  for(int i{length - 1}, j{}; i >= 0; i--, j++){
    B[j] = A[i];
  }
  for(int i{}; i < length; i++){
    A[i] = B[i];
  }
  delete []B;
}

void Array::Reverse(){
  for(int i{}, j{length - 1}; i < j; i++, j--){
    swap(&A[i], &A[j]);
  }
}

void Array::left_shift(){
  if(length <= size){
    for(int i{1}; i < length; i++){
      A[i - 1] = A[i];
    }
    A[length - 1] = 0;
  }
}

void Array::left_rotate(){
  int y{A[0]};
    for(int i{1}; i < length; i++){
    A[i - 1] = A[i];
  }
  A[length - 1] = y;
}

void Array::right_shift(){
  if(size > length){
    for(int i{length - 1}; i >= 0; i--){
      A[i + 1] = A[i];
    }
    A[0] = 0;
    length++;
  }else{
    for(int i{length - 1}; i >= 0; i--){
      A[i + 1] = A[i];
    }
    A[0] = 0;
  }
}

void Array::right_rotate(){
  int y{};
  for(int i{length - 1}; i >= 0; i--){
    A[i + 1] = A[i];
  }
  A[0] = 0;
}

void Array::insert_inSort(int y){
  int i{length - 1};
  if(length == size)
    return;
  while(i>= 0 && A[i] > y){
    A[i + 1] = A[i];
    i--;
  }
  A[i + 1] = y;
  length++;
}

int Array::isSorted(){
  for(int i{}; i < length - 1; i++){
    if(A[i] > A[i + 1]){
      return 0;
    }
  }
  return 1;
}

void Array::reArrange(){
  int i{}, j{length - 1};
  while(i < j){
    while(A[i] < 0){i++;}
    while(A[j] > 0){j--;}
    if(i < j){swap(&A[i], &A[j]);};
  }
}

Array* Array::merge(Array *y){
  int i{}, j{}, k{};
  Array *b = new Array;
  while(i < length && j < y->length){
    if(A[i] < y->A[j])
      b->A[k++] = A[i++];
    else 
      b->A[k++] = y->A[j++];
  }
  for(;i < length;i++)
    b->A[k++] = A[i];
  for(;j < y->length;j++)
    b->A[k++] = y->A[j];
  b->length = length + y->length;
  b->size = b->length;
  return b;
}

Array* Array::Union(Array *y){
  int i{}, j{}, k{};
  Array *b = new Array;
  while(i < length && j < y->length){
    if(A[i] < y->A[j])
      b->A[k++] = A[i++];
    else if(y->A[i] < A[i]){
      b->A[k++] = y->A[j++];
    }
    else{
      b->A[k++] = y->A[j++];
      i++;
    }
  }
  for(;i < length;i++)
    b->A[k++] = A[i];
  for(;j < y->length;j++)
    b->A[k++] = y->A[j];
  b->length = k;
  b->size = b->length;
  return b;
}

Array* Array::Intersection(Array *y){
  int i{}, j{}, k{};
  Array *b = new Array;
  while(i < length && j < y->length){
    if(A[i] < y->A[j])
      i++;
    else if(y->A[i] < A[i]){
      j++;
    }
    else {
      b->A[k++] = A[i++];
      j++;
    }
  }
  b->length = k;
  b->size = b->length;
  return b;
}

Array* Array::difference(Array *y){
  int i{}, j{}, k{};
  Array *b = new Array;
  while(i < length && j < y->length){
    if(A[i] < y->A[j])
      b->A[k++] = A[i++];
    else if(y->A[i] < A[i]){
      j++;
    }
    else{
      j++;
      i++;
    }
  }
  for(;i < length;i++)
    b->A[k++] = A[i];
  b->length = k;
  b->size = b->length;
  return b;
}


int main(){
  Array arr;
  // arr.display();
  // arr.add(5);
  // arr.display();
  // arr.insert(5, -1);
  // arr.display();
  // arr.delete_item(0);
  // arr.display();
  // arr.add(5);
  // arr.display();
  // std::cout << arr.recursive_binary_search(0, 4, 5);
  arr.sum_pair_unsorted_hash(10);
  return 0;

}