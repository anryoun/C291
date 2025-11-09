#include <stdio.h>
#include <stdlib.h>
#include "a3problem1.h"

int main(void){
	const int n = 5;
	const int C = 500;

	const char *questions[5] = {
		"What are local variables?",
		"What is an identifier?",
		"What is recursion?",
		"What is a pointer?",
		"What is the purpose of applyint static to a local array?"
	};

	const char *instructor_answers[5] = {
		"Variables defined in function definition are local variables. They can be accessed only in that function scope",
		"Identifiers are user defined names given to variables, functions and arrays",
		"A function calling itself again and again to compute a value is referred to as recursive function or recursion",
		"A pointer is a variable that stores the memory address of another variable as its value",
		"By making a local array definition static the array is not created and initialized every time the function is called, and it is not destroyed every time the function is exited"
	};

	printf("Welcome to the mini autograder (Cosine similarity based)\n");
	printf("Please answer the following %d questions (max %d characters each):\n\n", n, C-1);

	char **student_answers = getStudentAnswers((const char**)questions, n, C);
	if(!student_answers){
		fprintf(stderr, "Failed to get student answers.\n");
		return 1;
	}

	double total_marks = 0.0;

	printf("\n--- Results ---\n");
	for(int i = 0; i < n; i++){
		int dict_size = 0;

		int **vectors = ans2Vectors(instructor_answers[i], student_answers[i], &dict_size);
		if(!vectors){
			fprintf(stderr, "Error processing Q%d\n", i + 1);
			continue;
		}
		int *instr_vec = vectors[0];
		int *stud_vec = vectors[1];

		double sim = 0.0;
		if(dict_size > 0){
			sim = cosineSimilarity(instr_vec, stud_vec, dict_size);
		}
		double marks = convertSimilarityToMarks(sim);
		total_marks += marks;

		printf("Q%d: %.2f / 10.00 (similarity: %.4f, dict_size: %d)\n", i + 1, marks, sim, dict_size);

		if(instr_vec){
			free(instr_vec);
		}
		if(stud_vec){
			free(stud_vec);
		}
		free(vectors);
	}

	printf("\nTotal marks: %.2f / %.2f\n", total_marks, (double)(n * 10));

	for(int i = 0; i < n; i++){
		if(student_answers[i]){
			free(student_answers[i]);
		}
	}
	free(student_answers);

	return 0;
}
