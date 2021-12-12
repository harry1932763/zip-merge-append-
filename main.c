#include <stdio.h>
#include <string.h>

void append(char user_array[], char letter); 
void zip(char dest[],char input_array1[],char input_array2[], int length); 
void zip_leftovers(char dest[], char user_array_stream[], int start, int finish); 
char *merge(char dest[], char user_array1[],char user_array2[] ); 
char *reversed(char input_array[]);

#define sentence_size 350

int main(void) {
  char sentence1[sentence_size]; 
  char sentence2[sentence_size];  
  char combined[sentence_size*2] = { 0 }; 
  
  printf("enter your sentences: \n"); 
  scanf("%[^\n]%*c", sentence1); 
  scanf("%[^\n]%*c", sentence2);

  printf("\n%-11s%s","combined: " ,merge(combined, sentence1, sentence2));
  printf("\n%-11s%s","reversed: " ,reversed(combined));
  return 0;
} 

void append(char user_array[], char letter){ 
  // store the length of user_array
  int length = strlen(user_array);
  // set the last index to the element to be added
  user_array[length] = letter;  
  // add the null character to the end of the list 
  user_array[length+1] = '\0';  
} 

// function which takes turns storing elements from 2 lists with length being the amount of pairs to store. 
void zip(char dest[],char input_array1[],char input_array2[], int length){
  // 0 - n where n is the length specified by the user
  for (int i = 0; i < length; i++){
    // put the input_array1[i] element at the end of the destination array
    append(dest, input_array1[i]); 
    // put the input_array2[i] element at the end of the destination array
    append(dest, input_array2[i]); 
  }
}

// function to store the excess elements which had no pairs 
void zip_leftovers(char dest[], char user_array_stream[], int start, int finish){
  // range to access indexs, the range is decided by the user with start and finish
  for (int i = start; i < finish; i++){
    //add user_array_stream[i] to the end of the destination array 
    append(dest, user_array_stream[i]); 
  }
}

char *merge(char dest[], char user_array1[],char user_array2[] ){
  int length1 = strlen(user_array1); 
  int length2 = strlen(user_array2); 

  if (length1 == length2){
    zip(dest, user_array1, user_array2, length1);
  }
  else if(length1 < length2){
    zip(dest, user_array1, user_array2, length1);
    zip_leftovers(dest, user_array2, length1, length2); 
  }
    else{
    zip(dest, user_array1, user_array2, length2);
    zip_leftovers(dest, user_array1, length2, length1); 
  }
  char *dest_pointer = dest; 
  return dest_pointer; 
}

char *reversed(char input_array[]){
  int length = strlen(input_array);
  char reversed_array[sentence_size*2] = {0}; 
  for (int i = length; i >= 0; i-- ){
    append(reversed_array, input_array[i]);  
  }
  char *reversed = reversed_array; 
  return reversed; 
}