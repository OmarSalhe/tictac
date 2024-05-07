//Omar Salhe, Thursday Feb 29, 2024
// A program the runs a series of tests on inputted strings and returns results dependent on a specified criteria within each method
public class StringPractice {
  /* returns true if c is a punctuation mark or false otherwise
   * 
   * Punctuation mark is defined as:
   * apostrophe '
   * comma ,
   * period .
   * semicolon ;
   * colon :
   * exclamation point !
   * question mark ? 
   * 
   * (You don't have to worry about any others)
   */
  public static boolean isPunct(char c) {
    char punct[] = {'\'', ',', '.', ';', ':', '!', '?'};
    for (char isC : punct) // compares inputted char to list of punctuation
      if(isC == c){
        return true;
      }
    return false;
  }

  /*
   * returns the number of punctuation marks
   * found in s.
   *
   * call your isPunct( ) method. Do not compy and paste
   * the same logic into this function */
  public static int numPunct(String s) {
    int numPunct = 0;
    for(int i = 0; i < s.length(); i++){
      if(isPunct(s.charAt(i))){
        numPunct++;
      }
    }
    return numPunct;
  }
  
  /*
   * returns the number of punctuation marks
   * found in s starting at the given index.
   *
   * call your isPunct( ) method. Do not compy and paste
   * the same logic into this function */
  public static int numPunct(String s, int startIndex) {
    int numPunct = 0;
    for(int i = startIndex; i < s.length(); i++){
      if(isPunct(s.charAt(i))){
        numPunct++;
      }
    }
    return numPunct;
  }


  /*
   * returns the index of the first punctuation mark in s or
   * -1 if s contains no punctuation marks
   */
  public static int indexOfFirstPunct(String s) {
    for(int i = 0; i < s.length(); i++){
      if(isPunct(s.charAt(i))){
        return i;
      }
    }
    return -1;
  }

  /*
   * returns the index of the last occurrence of a punctuation
   * mark in s or -1 if s contains no punctuation
   * 
   * When implementing this function, call your isPunct( ) method.
   * Do not simply copy and paste the body of isPunct( ) into this method.
   */
  public static int indexOfLastPunct(String s) {
    int lastPunct = -1;
    for(int i = 0; i < s.length(); i++){ // passes through the entire string storing the most recent punctuation index.
      if (isPunct(s.charAt(i))){
        lastPunct = i;
      }
    }
    return lastPunct; // if none are found return the initial value of -1
  }

  /*
   * returns a new String which is the same as s but with
   * each instance of oldChar replaced with newChar
   */
  public static String substitute(String s, char oldChar, char newChar) {
    String newS = "";
    for(int i = 0; i < s.length(); i++){ // adds characters one at a time onto an empty string
      if(s.charAt(i) == oldChar){
        newS += newChar; // if old char is found add new char onto new string in its place
      }
      else{
        newS += s.charAt(i); // else continue copying old string
      }
    }
    return newS;
  }

  /*
   * returns a new String which is the same as s, but
   * with each instance of a punctuation mark replaced
   * with a single space character
   *
   * Use at least one of your other functions in your
   * solution to this.
   *
   */
  public static String substitutePunct(String s) {
    String newS = "";
    for(int i = 0; i < s.length(); i++){ // copies old string to new string character by character
      if(isPunct(s.charAt(i))){
        newS += " "; // if the index contains a punctuation place a space in its place in the new string
      }
      else{
        newS += s.charAt(i);
      }
    }
    return newS;
  }
  
  /*
   * returns a new String which is the same as s,
   * but with all of the punctuation
   * marks removed.
   *
   * Use at least one of your other functions
   * in your solution to this one.
   * 
   */
  public static String withoutPunct(String s) {
    String newS = "";
    for(int i = 0; i < s.length(); i++){
      if(isPunct(s.charAt(i))){
        continue; // if unwanted character is found skip over it
      }
      else{
        newS += s.charAt(i); // copies old string to new string
      }
    }
    return newS;
  }

  /* returns true if c is found in s or false otherwise */
  public static boolean foundIn(String s, char c) {
    for(int i = 0; i < s.length(); i++){
      if (s.charAt(i) == c){
        return true;
      }
    }
    return false;
  }

  /*
   * returns the number of times that a punctuation mark
   * immediately follows a character that's not a
   * punctuation mark
   */
  //needs test
  public static int numPunctAfterNonPunct(String s) {
    int num = 0, next_index;
    for(int i = 0, len = s.length(); i < len; i++){
      if (!(isPunct(s.charAt(i)))){
        next_index = i + 1;
        if(next_index < len && isPunct(s.charAt(next_index))){
          num++;
        }
      }
    }
    return num;
  }
  
  /*
   * Returns true of s is comprised of only punctuation or
   * false otherwise
   *
   * Use at least one of your other
   * functions in this one.
   */
  public static boolean onlyPunct(String s) {
    for(int i = 0; i < s.length(); i++){
      if(!(isPunct(s.charAt(i)))){
        return false;
      }
    }
    return true;
  }

  /*
   * Returns true of s contains no punctuation or
   * false otherwise
   *
   * Use at least one of your other
   * functions in this one.
   */
  public static boolean noPunct(String s) {
    for(int i = 0; i < s.length(); i++){
      if(isPunct(s.charAt(i))){
        return false;
      }
    }
    return true;
  }

  /*
   * returns true if s has two punctuation marks
   * right next to each other or false otherwise
   *
   * use at least one of your other methods
   * in your solution to this method
   */
  public static boolean consecutivePuncts(String s) {
    int next_index;
    for(int i = 0, len = s.length(); i < len; i++){
      if(isPunct(s.charAt(i))){
        next_index = i + 1;
        if(next_index < len && isPunct(s.charAt(next_index))){
          return true;
        }
      }
    }
    return false;
  }
}
