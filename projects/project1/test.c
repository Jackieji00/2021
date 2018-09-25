#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0;
#define true 1;

typedef int bool;

/*
 * Returns true if the given char is a digit from 0 to 9
 */
bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

/*
 * Returns true if lower alphabetic character
 */
bool is_lower_alphabetic(char c) {
	return c >= 'a' && c <= 'z';
}

/*
 * Returns true if upper alphabetic character
 */
bool is_upper_alphabetic(char c) {
	return c >= 'A' && c <= 'Z';
}

/*
 * Convert a string to an integer
 * returns 0 if it cannot be converted.
 */
int string_to_integer(char* input) {
	int result = 0;
	int length = strlen(input);
	int num_digits = length;
	int sign = 1;

	int i = 0;
	int factor = 1;

	if (input[0] == '-') {
		num_digits--;
		sign = -1;
	}

	for (i = 0; i < num_digits; i++, length--) {
		if (!is_digit(input[length-1])) {
			return 0;
		}
		if (i > 0) factor*=10;
		result += (input[length-1] - '0') * factor;
	}

	return sign * result;
}

/*
 * Returns true if the given base is valid.
 * that is: integers between 2 and 36
 */
bool valid_base(int base) {
	if(!(base >= 2 && base <= 36)) {
		return false;
	}
	return true;
}

/*
 * TODO
 * Returns true if the given string (char array) is a valid input,
 * that is: digits 0-9, letters A-Z, a-z
 * and it should not violate the given base and should not handle negative numbers
 */
bool valid_input(char* input, int base) {
  char* numbers = "0123456789";
  char* letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
  if (base<=10){
    char* numLetter = malloc(base+1);
    strncpy(numLetter,numbers,base);
    if (strspn(input,numLetter)!=strlen(input)){
      return false;
    }
  }else{
    int i;
    char* numLetter = malloc(base*2-9);
    strcpy(numLetter,numbers);
    for(i =0;i<(base*2-20);i++){
      // printf("%c\n", *(letters+i));
      *(numLetter+9+i) = *(letters+i);
      // printf("%s\n",numLetter);
    }
    // numLetter[i] = '\0';
    printf("%s\n",numLetter );
    if(strspn(input,numLetter)!=strlen(input)){
      return false;
    }
  }
  return true;
}
int* string_to_integer_array(char* str) {
	int* result;
	int i, str_offset = 0;
		result = malloc((strlen(str) + 1) * sizeof(int));
		result[strlen(str)] = -1;
	for(i = str_offset; str[i] != '\0'; i++) {
		if(is_digit(str[i])) {
			result[i - str_offset] = str[i] - '0';
		} else if (is_lower_alphabetic(str[i])) {
			result[i - str_offset] = str[i] - 'a' + 10;
		} else if (is_upper_alphabetic(str[i])) {
			result[i - str_offset] = str[i] - 'A' + 10;
		} else {
			printf("I don't know how got to this point!\n");
		}
	}
	return result;
}

/*
 * finds the length of a bignum...
 * simply traverses the bignum until a negative number is found.
 */
int bignum_length(int* num) {
	int len = 0;
	while(num[len] >= 0) { len++; }
	return len;
}

/*
 * TODO
 * Prints out a bignum using digits and lower-case characters
 * Current behavior: prints integers
 * Expected behavior: prints characters
 */
void bignum_print(int* num) {
	int i;
  int negativeCount =0;
	if(num == NULL) { return; }
	/* Handle negative numbers as you want */
	// i = bignum_length(num);
  // for(int count = 0;count < i ;count++){
  //   if (num[count]<0){
  //     negativeCount ++;
  //   }
  // }
  // int* positive = malloc((i-negativeCount) *sizeof(int));
  // int positiveCount = 0;
  // for(int c = 0;c<i;c++){
  //   if(num[c]>0){
  //     positive[positiveCount] = num[c];
  //     positiveCount++;
  //   }
  // }
	/* Then, print each digit */
	for(i = 0; num[i] >= 0; i++) {
    if(num[i]<10){
      printf("%d", num[i]);
    }else{
      printf("%c",(char)(num[i]+87));
    }
	}
	printf("\n");
}
/*
 * TODO
 * return true if input1 < input2, and false otherwise
 */
bool less_than(int* input1, int* input2) {
	if(bignum_length(input1)<bignum_length(input2)){
		return true;
	}else{
		for(int i=0;i<bignum_length(input1);i++){
			if(input1[i]<input2[i]){
				return true;
			}
		}
	}
	return false;
}


/*
 * TODO
 * return true if input1 > input2, and false otherwise
 */
bool greater_than(int* input1, int* input2) {
	if(bignum_length(input1)>bignum_length(input2)){
		return true;
	}else{
		for(int i=0;i<bignum_length(input1);i++){
			if(input1[i]>input2[i]){
				return true;
			}
		}
	}
	return false;
}

/*
 * TODO
 * return true if input1 == input2, and false otherwise
 */
bool equal_to(int* input1, int* input2) {
	if (bignum_length(input1)==bignum_length(input2)){
		for(int i=0;i<bignum_length(input1);i++){
			if(input1[i]!=input2[i]){
				return false;
			}
		}
		return true
	}
	return false;
}


/*
 * TODO
 * multiply input1 * input2
 */
int* multiply(int* input1, int* input2, int base) {
	int carry = 0;
  int l1 = bignum_length(input1);
  int l2 = bignum_length(input2);
  printf("\nl1:%d,l2:%d\n",l1,l2);
  int lResult,d,mul1,mul2;
	int lengthG = (greater_than(input1,input2))?l1:l2;
	int* result;
	if(input1[0]*input2[0]>=base){
		result = malloc((l1+l2)*sizeof(int));
    lResult = l1+l2;
	}else{
		result = malloc((lengthG)*sizeof(int));
    lResult = l1+l2-1;
	}
  printf("lResult:%d\n",lResult);
  result[lResult]= -1;
	for(int i =lResult-1;i>=0;i--){
    d=lResult-i;
    mul1=(l1-d>=0)?input1[l1-d]:0;
    mul2=(l2-d>=0)?input2[l2-d]:0;
		result[i] = mul1*mul2%base+carry;
		carry =(mul1*mul2+result[i])/base;
    printf("i:%d,input1:%d,input2:%d\n",i,mul1,mul2);
    printf("carry:%d,result %d\n",carry,result[i]);
	}
	return result;
}


int main(){
  char* input = "18FGA";
  printf("vaild input:%d\n",valid_input(input,18));
  int arr[] = {9,10,16,5,-1};
  bignum_print(arr);
  int la1[]= {5, 8, -1};
  int la2[] = {6, 3, -1};
  printf("less_than: %d\n",less_than(la1,la2));
  printf("multiply: ");
  bignum_print(multiply(la1,la2,10));
}
