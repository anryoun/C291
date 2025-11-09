#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a3problem1.h"

// Utility functions
char* copyNCharacters(char* destination, const char* source, size_t num){
	if(!destination || !source) return destination;
	size_t i;
	for(i = 0; i < num && source[i] != '\0'; i++){
		destination[i] = source[i];
	}
	// put null if we didn't copy to num
	if(i < num){
		destination[i] = '\0';
	} else {
		destination[num-1] = '\0';
	}
	return destination;
}

void* fillMemory(void * ptr, int value, size_t num){
	if(!ptr) return ptr;
	unsigned char *p = (unsigned char*)ptr;
	unsigned char v = (unsigned char)value;
	size_t i;
	for(i = 0; i < num; i++){
	       p[i] = v;
	}
	return ptr;
}

char* findCharacter(const char* str, int character){
	if(!str) return NULL;
	const char c = (char)character;
	while(*str){
		if(*str == c){
			return (char*)str;
		}
		str++;
	}
	if(c == '\0'){
		return (char*)str;
	}
	return NULL;
}

size_t getStringLength(const char* str){
	if(!str) return 0;
	const char *s = str;
	size_t len = 0;
	while(*s++){
		len++;
	}
	return len;
}

char* copyString(char* destination, const char* source){
	if(!destination || !source) return destination;
	size_t i = 0;
	while(source[i] != '\0'){
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

size_t findFirstMismatch(const char* str1, const char* str2){
	if(!str1) return 0;
	if(!str2) return getStringLength(str1);
	size_t i = 0;
	while(str1[i] != '\0'){
		const char c = str1[i];
		size_t j = 0;
		int found = 0;
		while(str2[j] != '\0'){
			if(c == str2[j]){
				found = 1;
				break;
			}
			j++;
		}
		if(found) break;
		i++;
	}
	return i;
}

int compareStrings(const char* str1, const char* str2){
	if(!str1 && !str2) return 0;
	if(!str1) return -1;
	if(!str2) return 1;
	size_t i = 0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i]){
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}
		i++;
	}
	return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char* duplicateString(const char* str){
	if(!str) return NULL;
	size_t len = getStringLength(str);
	char *dup = (char*)malloc(len + 1);
	if(!dup) return NULL;
	size_t i;
	for(i = 0; i < len; i++){
		dup[i] = str[i];
	}
	dup[len] = '\0';
	return dup;
}

char convertToLowercase(char c){
	if(c >= 'A' && c <= 'Z') return (char)(c + ('a' - 'A'));
	return c;
}

void convertStrToLower(char* str){
	if(!str) return;
	size_t i = 0;
	while(str[i] != '\0'){
		str[i] = convertToLowercase(str[i]);
		i++;
	}
}

size_t findInitialMatch(const char * str1, const char * str2){
	if(!str1) return 0;
	if(!str2) return 0;
	size_t i = 0;
	while(str1[i] != '\0'){
		const char c = str1[i];
		size_t j = 0;
		int in_set = 0;
		while(str2[j] != '\0'){
			if(c == str2[j]){
				in_set = 1;
				break;
			}
			j++;
		}
		if(!in_set) break;
		i++;
	}
	return i;
}

char* getStringFromUser(int len){
	if(len <= 0) return NULL;
	char *buf = (char*)malloc((size_t)len);
	if(!buf) return NULL;
	if(fgets(buf, len, stdin) == NULL){
		// On error, returns an empty string
		buf[0] = '\0';
		return buf;
	}
	size_t L = getStringLength(buf);
	if(L > 0 && buf[L-1] == '\n'){
		buf[L-1] = '\0';
	}
	return buf;
}

// Tokenizer function
char** tokenizeString(char* str, int *num_tokens){
	if(!str){
		if(num_tokens){
			*num_tokens = 0;
		}
		return NULL;
	}
	int count = 0;
	char *p = str;
	while(*p){
		while(*p == ' '){
			p++;
		}
		if(*p == '\0') break;
		count++;
		while(*p && *p != ' '){
			p++;
		}
	}

	if(num_tokens){
		*num_tokens = count;
	}
	if(count == 0) return NULL;

	char **tokens = (char**)malloc(sizeof(char*) * count);
	if(!tokens){
		if(num_tokens){
			*num_tokens = 0;
		}
		return NULL;
	}

	int idx = 0;
	p = str;
	while(*p){
		while(*p == ' '){
			p++;
		}
		if(*p == '\0') break;
		char *start = p;
		size_t toklen = 0;
		while(*p && *p != ' '){
			p++;
			toklen++;
		}
		char *tok = (char*)malloc(toklen + 1);
		if(!tok){
			for(int k = 0; k < idx; k++){
				free(tokens[k]);
			}
			free(tokens);
			if(num_tokens){
				*num_tokens = 0;
			}
			return NULL;
		}
		size_t i;
		for(i = 0;i < toklen; i++){
			tok[i] = start[i];
		}
		tok[toklen] = '\0';
		tokens[idx++] = tok;
	}
	return tokens;
}

// Specified functions

char** createDictionary(char* instructor_answer, const char* student_answer, int* dict_size){
	if(!instructor_answer && !student_answer){
		if(dict_size){
			*dict_size = 0;
		}
		return NULL;
	}

	char *student_copy = NULL;
	if(student_answer){
		student_copy = duplicateString(student_answer);
	}

	int instr_tokens = 0;
	char **instr_tok = NULL;
	if(instructor_answer){
		instr_tok = tokenizeString(instructor_answer, &instr_tokens);
	}

	int stud_tokens = 0;
	char **stud_tok = NULL;
	if(student_copy){
		stud_tok = tokenizeString(student_copy, &stud_tokens);
	}

	int total = instr_tokens + stud_tokens;
	if(total == 0){
		if(dict_size){
			*dict_size = 0;
		}
		if(instr_tok){
			free(instr_tok);
		}
		if(stud_tok){
			free(stud_tok);
		}
		free(student_copy);
		return NULL;
	}

	char **dict = (char**)malloc(sizeof(char*) * total);
	if(!dict){
		if(instr_tok){
			for(int i = 0; i < instr_tokens; i++){
				free(instr_tok[i]);
				free(instr_tok);
			}
		}
		if(stud_tok){
			for(int i = 0; i < stud_tokens; i++){
				free(stud_tok[i]);
				free(stud_tok);
			}
		}
		free(student_copy);
		if(dict_size){
			*dict_size = 0;
		}
		return NULL;
	}

	int U = 0;

	int int_exists(const char *w, char **dict, int U){
		for(int i = 0; i < U; i++){
			if(compareStrings(dict[i], w) == 0) return 1;
		}
		return 0;
	};

	for(int i = 0; i < instr_tokens; i++){
		if(!int_exists(instr_tok[i], dict, U)){
			dict[U++] = duplicateString(instr_tok[i]);
		}
	}

	for(int i = 0; i < stud_tokens; i++){
		if(!int_exists(stud_tok[i], dict, U)){
			dict[U++] = duplicateString(stud_tok[i]);
		}
	}

	if(instr_tok){
		for(int i = 0; i < instr_tokens; i++){
			free(instr_tok[i]);
		}
		free(instr_tok);
	}
	if(stud_tok){
		for(int i = 0; i < stud_tokens; i++){
			free(stud_tok[i]);
		}
		free(stud_tok);
	}
	free(student_copy);

	if(dict_size){
		*dict_size = U;
	}
	return dict;
}

int* createVector(const char** dictionary, char* answer, int dict_size){
	if(!dictionary || !answer || dict_size <= 0) return NULL;

	int tok_count = 0;
	char **tokens = tokenizeString(answer, &tok_count);
	int *vec = (int*)malloc(sizeof(int) * dict_size);
	if(!vec){
		if(tokens){
			for(int i = 0; i < tok_count; i++){
				free(tokens[i]);
				free(tokens);
			}
		}
		return NULL;
	}
	for(int i = 0; i < dict_size; i++){
		vec[i] = 0;
	}

	for(int i = 0; i < tok_count; i++){
		for(int j = 0; j < dict_size; j++){
			if(compareStrings(dictionary[j], tokens[i]) == 0){
				vec[j] += 1;
				break;
			}
		}
	}
	for(int i = 0; i < tok_count; i++){
		free(tokens[i]);
	}
	free(tokens);
	return vec;
}

int** ans2Vectors(const char* instructor_answer, const char* student_answer, int *dict_size){
	if(!instructor_answer && !student_answer){
		if(dict_size){
			*dict_size = 0;
		}
		return NULL;
	}

	char *instr_copy = instructor_answer ? duplicateString(instructor_answer) : duplicateString("");
	char *stud_copy = student_answer ? duplicateString(student_answer) : duplicateString("");

	convertStrToLower(instr_copy);
	convertStrToLower(stud_copy);

	int U = 0;
	char **dict = createDictionary(instr_copy, stud_copy, &U);

	int *instr_vec = NULL;
	int *stud_vec = NULL;
	if(U > 0){
		instr_vec = createVector((const char**)dict, instr_copy, U);
		stud_vec = createVector((const char**)dict, stud_copy, U);
	} else {
		instr_vec = (int*)malloc(sizeof(int) * 1);
		stud_vec = (int*)malloc(sizeof(int) * 1);
		if(instr_vec){
			instr_vec[0] = 0;
		}
		if(stud_vec){
			stud_vec[0] = 0;
		}
	}

	if(dict){
		for(int i = 0; i < U; i++){
			free(dict[i]);
		}
		free(dict);
	}

	free(instr_copy);
	free(stud_copy);

	int **ret = (int**)malloc(sizeof(int*) * 2);
	if(!ret){
		if(instr_vec){
			free(instr_vec);
		}
		if(stud_vec){
			free(stud_vec);
		}
		if(dict_size){
			*dict_size = 0;
		}
		return NULL;
	}
	ret[0] = instr_vec;
	ret[1] = stud_vec;
	if(dict_size){
		*dict_size = U;
	}
	return ret;
}

double cosineSimilarity(const int* instructor_vector, const int* student_vector, int dict_size){
	if(!instructor_vector || !student_vector || dict_size <= 0) return 0.0;
	double dot = 0.0;
	double normA = 0.0;
	double normB = 0.0;
	for(int i = 0; i < dict_size; i++){
		double a = (double)instructor_vector[i];
		double b = (double)student_vector[i];
		dot += a * b;
		normA += a * a;
		normB += b * b;
	}
	if(normA <= 0.0 || normB <= 0.0) return 0.0;
	return dot / (sqrt(normA) * sqrt(normB));
}

double convertSimilarityToMarks(double similarity){
	if(similarity < 0.0) similarity = 0.0;
	if(similarity > 1.0) similarity = 1.0;
	return similarity * 10.0;
}

char** getStudentAnswers(const char** questions, int n, int len){
	if(!questions || n <= 0 || len <= 0) return NULL;
	char **answers = (char**)malloc(sizeof(char*) * n);
	if(!answers) return NULL;
	for(int i = 0; i < n; i++){
		printf("Q%d: %s\n", i+1, questions[i]);
		printf("Your answer: ");
		fflush(stdout);
		char *ans = getStringFromUser(len);
		if(!ans){
			ans = (char*)malloc(1);
			if(ans){
				ans[0] = '\0';
			}
		}
		answers[i] = ans;
	}
	return answers;
}

