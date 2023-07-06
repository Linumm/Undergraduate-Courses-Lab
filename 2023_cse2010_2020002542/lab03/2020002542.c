#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ISFULL 1
#define ISEMPTY 2
#define DIVIDEZERO 3

FILE *fin;
FILE *fout;

typedef struct Stack{
	int *key;
	int top; //index of top
	int max_stack_size;
}Stack;

Stack* CreateStack(int max);
void Push(Stack* S, int X);
int Pop(Stack* S);
int Top(Stack* S);

void DeleteStack(Stack* S);
int IsEmpty(Stack* S);
int IsFull(Stack* S);

void main(int argc, char *argv[]){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	Stack* stack;
	char input_str[101];
	int max=20, i=0,a,b,result, error_flag=0;

	fgets(input_str,101,fin);
	stack = CreateStack(max);

	
	fprintf(fout, "top numbers : ");
	while(input_str[i]!='#'){
		// Consider the case of operators (+ - * / %) and single digit operands
		// while in loop, if there occurs error, change "error_flag"

		if (isdigit(input_str[i])){
			if (IsFull(stack)){
				error_flag = ISFULL;
				//printf("error_flag changed: ISFULL\n");
			}
			else 
				Push(stack, input_str[i]-48); //atoi error->just calculate by ASCII 
		}
		else{
			a = Pop(stack);

			if (stack->top >= 0){ // Since we have to "Pop" 2 elements from stack.
				b = Pop(stack);

				if (input_str[i] == '+') Push(stack, b+a);
				else if (input_str[i] == '-') Push(stack, b-a);
				else if (input_str[i] == '*') Push(stack, b*a);
				else if (input_str[i] == '/'){
					if (a == 0){
						error_flag = DIVIDEZERO;
						break;
					}
					Push(stack, b/a);
				}
				else if (input_str[i] == '%'){
					if (a == 0){
						error_flag = DIVIDEZERO;
						break;
					}
					Push(stack, b%a);
				}
			}
			else{
				error_flag = ISEMPTY;
				break;
			}
		}
		
		
		if(error_flag) break; //If error_flag > 0 : break

		int t = Top(stack); // return top stack
		fprintf(fout, "%d ",t); // top numbers : t1 t2 t3 ...
		result=t; // The Final t value 
		i++;
	}

	if(error_flag == ISFULL){
		fprintf(fout, "\nerror : invalid postfix expression, stack is full!\n");
	}
	else if(error_flag == ISEMPTY){
		fprintf(fout, "\nerror : invalid postfix expression, stack is empty!\n");
	}
	else if(error_flag == DIVIDEZERO){
		fprintf(fout, "\nerror : invalid postfix expression, divide by zero!\n");
	}

	else{
		if(stack->top+1 > 1){
			fprintf(fout, "\nerror : invalid postfix expression, %d elements are left!\n", stack->top+1);
		}
		else{
			fprintf(fout, "\nevaluation result : %d\n",result);
		}
	}
	fclose(fin);
	fclose(fout);
	DeleteStack(stack);
}

//Function define
Stack* CreateStack(int max){
    Stack* tmp = malloc(sizeof(struct Stack));
    tmp->max_stack_size = max; // Be careful of index. last element is key[max-1]
    tmp->key = malloc(sizeof(int) * max);
	tmp->top = -1;
    return tmp;
}

void DeleteStack(Stack* S){ 
	//clear the memory of key(array) first then clear stack
    free(S->key);
    free(S);
}

void Push(Stack* S, int X){ 
    // First make 'top' +1 since we push new one and then access with '+1top'
	S->top += 1; 
	S->key[S->top] = X;
	//for error catching VV
	//printf("new element pushed: %d\n", S->key[S->top]); 
	//printf("now top index: %d\n", S->top);
}

int Pop(Stack* S){
	int topVal = S->key[S->top];
	S->key[S->top] = -1; //let the empty state value as -1
	S->top -= 1;
	return topVal;
}

int Top(Stack* S){
	//printf("TOP() : %d\n", S->key[S->top]);
    return S->key[S->top];
}

int IsFull(Stack* S){
    if (S->top == S->max_stack_size - 1) return 1; //watch out about index
    else return 0;
}

int IsEmpty(Stack* S){
    if (S->top == -1) return 1;
    else return 0;
}
