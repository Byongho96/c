#include <stdio.h>
#include <string.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int inorder_to_postorder(char* inorder) {
    char stack[100];
    int p, N;

    // initial setting
    N = strlen(inorder);
    inorder[N]=')';
    stack[0] = '('; 
    p = 0;
    for(int i=0; i<=N; i++) {
        if (inorder[i] == '(') {
            stack[++p]  = inorder[i];
        } else if (inorder[i] == ')') {
            while (stack[p] != '(') {
                printf("%c", stack[p--]);
            }
            p--;
        } else if(inorder[i] == '+' || inorder[i] == '-') {
			while (stack[p] != '(') {
				printf("%c", stack[p--]);
            }
			stack[++p] = inorder[i];
		} else if(inorder[i] == '*' || inorder[i] == '/') {
			while (stack[p]!='(' && stack[p] != '+' && stack[p] != '-') {
				printf("%c", stack[p--]);
            }
			stack[++p] = inorder[i];
		} else {
            printf("%c", inorder[i]);
        }
    }
}

int main() {
    char inorder[101]; // including \0 
    scanf("%s", inorder);

    inorder_to_postorder(inorder);
    return 0;
}