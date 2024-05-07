public class ArrayPractice {
  /* sets every item in A[] to initialValue */
  public static void initialize(int A[], int initialValue) {
    for(int i = 0, len = A.length; i < len; i++){
      A[i] = initialValue;
    }
  }

  
  /* returns the number of times that x appears in A[] */
  public static int numOccurrences(int A[], int x) {
    int numOfX = 0;
    for(int i = 0, len = A.length; i < len; i++){
      if(x == A[i]){
        numOfX++;
      }
    }
    /* placeholder so that the code compiles */
    return numOfX;
  }

  /* replaces all occurrences of x with y */
  public static void replace(int []A, int x, int y) {
    for(int i = 0, len = A.length; i < len; i++){
      if(x == A[i]){
        A[i] = y;
      }
    }
  }

  /* returns the index of the first occurrence of
   * x in A[] or -1 if x doesn't exist in A[] */
  public static int find(int A[], int x) {
    for(int i = 0, len = A.length; i < len; i++){
      if(x == A[i]){
        return i;
      }
    }
    /* placeholder so that the code compiles */
    return -1;
  }

  /* Returns the index of the first occurrence of
   * item within the first n elements of A[] or -1
   * if item is not among the first n elements of A[] */
  public static int findN(int A[], int item, int n) {
    for(int i = 0; i < n; i++){
      if(item == A[i]){
        return i;
      }
    }
    /* placeholder so that the code compiles */
    return -1;
  }

  /* returns the index of the last occurrence of
   * x in A[] or -1 if x doesn't exist in A[] */
  public static int findLast(int A[], int x) {
    for(int i = A.length - 1; i > - 1; i--){
      if(x == A[i]){
        return i;
      }
    }
    /* placeholder so that the code compiles */
    return -1;
  }

  /* returns the largest item found in A */
  public static int largest(int A[]) {
    int largest = 0;
    for(int i = 0, len = A.length; i < len; i++){
      if (largest < A[i]){
        largest = A[i];
      }
    }
    /* placeholder so that the code compiles */
    return largest;
}

  /* returns the index of the largest item found in A */
  public static int indexOfLargest(int A[]) {
    int largest = 0, largestIndex = 0;
    for(int i = 0, len = A.length; i < len; i++){
      if (largest < A[i]){
        largest = A[i];
        largestIndex = i;
      }
    }
    /* placeholder so that the code compiles */
    return largestIndex;
  }


  /* returns a reference to a two dimensional array with
   * n rows and n columns with 1s down the top-left to 
   * bottom-right diagonal and with 0s everywhere else
   * 
   * if n <= 0 returns null
   */
  public static int[][] eye(int n) {
    if (n <= 0){
      return null;
    }

    int arr[][] = new int[n][n];
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if (i == j){
          arr[i][j] = 1;
          continue;
        }
        arr[i][j] = 0;
      }
    }
    return arr;
  }
  
  /* inserts n into A[] at A[index] shifting all */
  /*  the previous items one place to the right. For example */
  /*  if A is  */
  /*   |---+---+---+---+---+---+---+---+---+---| */
  /*   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | */
  /*   |---+---+---+---+---+---+---+---+---+---| */
  /*   | 5 | 7 | 6 | 9 | 4 | 3 | 0 | 0 | 0 | 0 | */
  /*   |---+---+---+---+---+---+---+---+---+---| */

  /*   and we call insert(A, 15, 1), A then becomes */

  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*   | 0 |  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | */
  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*   | 5 | 15 | 7 | 6 | 9 | 4 | 3 | 0 | 0 | 0 | */
  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*  the element in A[] that's in the right-most */
  /*    position is removed.                      */
  /*                                              */
  /*  if index < 0 or index >= A.length-1, the method */
  /*                                    does nothing */
  public static void insert(int A[], int n, int index) {
    if(index < 0 || index >= A.length - 1){
      return;
    }
    for(int i = index, newVal = n, oldVal; i < A.length; i++){
      oldVal = A[i];
      A[i] = newVal;
      newVal = oldVal;
    }
  }

  /* returns a new array consisting of all of the
   * elements of A[] */
  public static int[] copy(int A[]) {
    int len = A.length;
    int B[] = new int[len];
    for(int i = 0 ; i < len; i++){
      B[i] = A[i];
    }
    return B;
  }

  /* Returns a new array consisting of all of the
     first n elements of A[]. If n>A.length, returns a
     new array of size n, with the first A.length elements
     exactly the same as A, and the remaining n-A.length elements
     set to 0. If n<=0, returns null. */
  public static int[] copyN(int A[], int n) {
    if(n <= 0){
      return null;
    }
    if(n > A.length){
      int B[] = new int[n];
      for(int i = 0; i < n; i++){
        if (i < A.length){
          B[i] = A[i];
          continue;
        }
        B[i] = 0;
      }
      return B;
    }
    else{
      int B[] = new int[n];
      for(int i = 0; i < n; i++){
        B[i] = A[i];
      }
      return B;
    }
  }

  /* returns a new array consisting of all of the
   * elements of A[] followed by all of the
   * elements of B[]. For example, if 
   A[] is: {10,20,30} and 
   B[] is: {5, 9, 38}, the method returns the
   array : {10,20,30,5,9,38} */
  public static int[] copyAll(int A[], int B[]) {
    int C[] = new int[A.length + B.length];

    for(int i = 0, len = C.length; i < len; i++){
      if(i < A.length){
        C[i] = A[i];
        continue;
      }
      C[i] = B[i - A.length];
    }
    return C;
  }

  /* reverses the order of the elements in A[].
   * For example, if A[] is:
   {10,20,30,40,50}, after the method, A[] would
   be {50,40,30,20,10} */
  public static void reverse(int A[]) {
    int len = A.length;
    int B[] = new int[len];
    for(int i = len - 1; i > -1; i-- ){
      B[len - i - 1] = A[i];
    }
    for(int i = 0; i < len; i++){
      A[i] = B[i];
    }
  }

  /* Extra credit:
   *
   * Returns a new array consisting of all of the
   * elements of A, but with no duplicates. For example,
   * if A[] is {10,20,5,32,5,10,9,32,8}, the method returns
   * the array {10,20,5,32,9,8} */
  public static int[] uniques(int A[]) {
    int unique = 0;
    int tmp[] = new int[A.length];
  
    for(int i = 0, len = A.length; i < len; i++){
      boolean isUnique = true;
      for(int j = 0; j < len; j++){
        if(A[i] == tmp[j]){
          isUnique = false;
          break;
        }
      }
      if(isUnique){
        tmp[unique] = A[i];
        unique++;
      }
    }
    return copyN(tmp, unique);
  }
}
