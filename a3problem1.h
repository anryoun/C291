#ifndef A3PROBLEM1_H
#define A3PROBLEM1_H
#include <stddef.h>

// Utility functions
char* copyNCharacters(char* destination, const char* source, size_t num);
void* fillMemory(void * ptr, int value, size_t num);
char* findCharacter(const char* str, int character);
size_t getStringLength(const char* str);
char* copyString(char* destination, const char* source);
size_t findFirstMismatch(const char* str1, const char* str2);
int compareStrings(const char* str1, const char* str2);
char** tokenizeString(char* str, int *num_tokens);
char* duplicateString(const char* str);
char convertToLowercase(char c);
void convertStrToLower(char* c);
size_t findInitialMatch(const char * str1, const char * str2);
char* getStringFromUser(int len);

// Specific functions
char** getStudentAnswers(const char** questions, int n, int len);
int** ans2Vectors(const char* instructor_answer, const char* student_answer, int *dict_size);
char** createDictionary(char* instructor_answer, const char* student_answer, int* dict_size);
int* createVector(const char** dictionary, char* answer, int dict_size);
double cosineSimilarity(const int* instructor_vector, const int* student_vector, int dict_size);
double convertSimilarityToMarks(double similarity);

#endif
