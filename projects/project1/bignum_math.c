
/* -----------
 * bignum_math.c
 * Project for CSCI 2021, Fall 2018, Professor Chris Dovolis
 * orginially written by Andy Exley
 * modified by Ry Wiese, Min Choi, Aaron Councilman
 * ---------- */

 /*name: Jackie Ji
  *x500: JI000011
  */
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
   if(valid_base(base)){
		 if (base<=10){                                  /*if it is all digit*/
	     char* numLetter = malloc(base+1);             /*create an array that only contains vaild numbers*/
	     strncpy(numLetter,numbers,base);
	     if (strspn(input,numLetter)!=strlen(input)){  /*check the matching length if is same as the input*/
	       return false;
	     }
	   }else{                                          /*if it involves letters*/
	     char* numLetter = malloc(base*2-9);           /*create an array that only contains vaild numbers and letters*/
	     strcpy(numLetter,numbers);
	     for(int i =0;i<(base*2-20);i++){
	       *(numLetter+10+i) = *(letters+i);
	     }
	     if(strspn(input,numLetter)!=strlen(input)){   /*check the matching length if is same as the input*/
	       return false;
	     }
	   }
	   return true;
	 }else{                                            /*if it base is not valid*/
		 return false
	 }
 }

/*
 * converts from an array of characters (string) to an array of integers
 */
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
 	if(num == NULL) { return; }
 	/* Handle negative numbers as you want */
 	i = bignum_length(num);
 	/* Then, print each digit */
 	for(i = 0; num[i] >= 0; i++) {
     if(num[i]<10){
       printf("%d", num[i]);
     }else{
       printf("%c",(char)(num[i]+87));
     }
 	}
 }

/*
 *	Helper for reversing the result that we built backward.
 *  see add(...) below
 */
void reverse(int* num) {
	int i, len = bignum_length(num);
	for(i = 0; i < len/2; i++) {
		int temp = num[i];
		num[i] = num[len-i-1];
		num[len-i-1] = temp;
	}
}

/*
 * addition of input1 and input2
 * PROVIDED FOR GUIDANCE
 */
int* add(int* input1, int* input2, int base) {
	int len1 = bignum_length(input1);
	int len2 = bignum_length(input2);
	int resultlength = ((len1 > len2)? len1 : len2) + 2;
	int* result = (int*) malloc (sizeof(int) * resultlength);
	int r = 0;
	int carry = 0;
	int sign = input1[len1];
	int num1, num2;

	len1--;
	len2--;

	while (len1 >= 0 || len2 >= 0) {
	        if (len1 >= 0) {
        	    num1 = input1[len1];
	        } else {
        	    num1 = 0;
        	}

		if (len2 >= 0) {
		    num2 = input2[len2];
		} else {
		    num2 = 0;
		}

		result[r] = (num1 + num2 + carry) % base;
		carry = (num1 + num2 + carry) / base;

		len1--;
		len2--;
		r++;
	}
	if (carry > 0) {
		result[r] = carry;
		r++;
    	}
	result[r] = sign;
	reverse(result);
	return result;
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
   int lResult,mul1;
 	 int* result;
   int* mul;
 	 if(input1[0]*input2[0]>=base){               /*calculate the result length*/
 		 result = malloc((l1+l2+1)*sizeof(int));
     mul = malloc((l1+l2+1)*sizeof(int));
     lResult = l1+l2+1;
 	 }else{
 		 result = malloc((l1+l2)*sizeof(int));
     mul = malloc((l1+l2)*sizeof(int));
     lResult = l1+l2;
 	 }
     result[lResult-1]= -1;
     mul = malloc((l1+l2)*sizeof(int));
   for(int z=0;z<=l1+l2;z++){                   /*set inital value at zero*/
     mul[z]=0;
   }
   for(int i=0;i<l1;i++){                       /*calculate the result on each place without carryover*/
     for(int j=0;j<l2;j++){
       mul[j+i]=input1[i]*input2[j]+mul[j+i];
			 printf("[%d]:%d\n",j+i,mul[j+i] );
     }
   }
   for(int c=lResult-2;c>=0;c--){               /*calculate the carryover part and place each digit on its place*/
     if(mul[0]>base){                           /*if check the length,so that to find mul index*/
			 mul1=(c-1>=0)?mul[c-1]:0;
		 }else{
			 mul1=mul[c];
		 }
     result[c]=(mul1+carry)%base;
		 printf("%d,%d,%d\n",c,result[c],lResult);
     carry = (mul1+carry)/base;
   }
 	return result;
 }

/*
 * TODO
 * This function is where you will write the code that performs the heavy lifting,
 * actually performing the calculations and comparisons on input1 and input2.
 * This function prints the result using printf. It does not return any value.
 * The text printed should always be of the form
 *    Result: ...
 * Where the ... is either a number of one of 'true' or 'false'.
 * See the project write-up for examples.
 * HINT: For better code structure, use helper functions.
 */
void perform_operation(int* input1, int* input2, char op, int base) {

	if(op == '+') {
		int* result = add(input1, input2, base);
		printf("Result: ");
		bignum_print(result);
		printf("\n");
		free(result);
	}
	/*
	 * TODO
	 * Handle multiplication, less than, greater than, and equal to
	 */
	 else if(op == '*'){
		int* result = multiply(input1, input2, base);
 		printf("Result: ");
 		bignum_print(result);
 		printf("\n");
 		free(result);
	}else if(op=='<'){
		bool r = less_than(input1, input2);
		printf("Result: ");
		char* result = (r==1)?"true":"false";
		printf("%s\n",result);
	}else if(op=='>'){
		bool r = greater_than(input1, input2);
		printf("Result: ");
		char* result = (r==1)?"true":"false";
		printf("%s\n",result);
	}else{
		bool r = equal_to(input1, input2);
		printf("Result: ");
		char* result = (r==1)?"true":"false";
		printf("%s\n",result);
	}
}

/*
 * Print to "stderr" and exit program
 */
void print_usage(char* name) {
	fprintf(stderr, "----------------------------------------------------\n");
	fprintf(stderr, "Usage: %s base input1 operation input2\n", name);
	fprintf(stderr, "base must be number between 2 and 36, inclusive\n");
	fprintf(stderr, "input1 and input2 are arbitrary-length integers\n");
	fprintf(stderr, "Permited operations are allowed '+', '*', '<', '>', and '='\n");
	fprintf(stderr, "----------------------------------------------------\n");
	exit(1);
}


/*
 * MAIN: Run the program and tests your functions.
 * sample command: ./bignum 4 12 + 13
 * Result: 31
 */
int main(int argc, char** argv) {

	int input_base;

	int* input1;
	int* input2;

	if(argc != 5) {
		print_usage(argv[0]);
	}

	input_base = string_to_integer(argv[1]);

	if(!valid_base(input_base)) {
		fprintf(stderr, "Invalid base: %s\n", argv[1]);
		print_usage(argv[0]);
	}


	if(!valid_input(argv[2], input_base)) {
		fprintf(stderr, "Invalid input1: %s\n", argv[2]);
		print_usage(argv[0]);
	}

	if(!valid_input(argv[4], input_base)) {
		fprintf(stderr, "Invalid input2: %s\n", argv[4]);
		print_usage(argv[0]);
	}

	char op = argv[3][0];
	if(op != '+' && op != '*' && op != '<' && op != '>' && op != '=') {
		fprintf(stderr, "Invalid operation: %s\n", argv[3]);
		print_usage(argv[0]);
	}

	input1 = string_to_integer_array(argv[2]);
	input2 = string_to_integer_array(argv[4]);

	perform_operation(input1, input2, op, input_base);

	free(input1);
	free(input2);

	exit(0);
}
