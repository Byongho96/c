#include <stdio.h>

#define fp(a,b,c) for(int a=b; a<c+1; a++)

int graph[100000][2];

void quick_sort(int left, int right)
{
	int q, r, m;
	int s_1, s_2;

	if (right > left){
		q = left - 1, r = right + 1;
		m = graph[(left + right) / 2][0];

		while (1){
			while (graph[++q][0] < m);
			while (graph[--r][0] > m);

			if (q >= r) break;

			s_1 = graph[q][0], graph[q][0] = graph[r][0], graph[r][0] = s_1;
			s_2 = graph[q][1], graph[q][1] = graph[r][1], graph[r][1] = s_2;
		}

		quick_sort(left, q - 1);
		quick_sort(r + 1, right);
	}
}


int main(void)
{

    int N, a, b, ans_idx = 0;
    int M, i, j;
    int in[32001], out[32001], ans[32001];

	scanf("%hd %d", &N, &M);

	fp(i, 1, M){
		scanf("%hd %hd", &a, &b);
		graph[i-1][0] = a, graph[i-1][1] = b;
		out[a]++, in[b]++;
	}

	quick_sort(0, M - 1);

    // Set the starts
	fp(i, 1, N){
		out[i] += out[i - 1];   // cumlative sum
		if (in[i] == 0){
            ans[ans_idx++] = i;
		}
	}

    // Topological sort
    int cur, nxt;
	fp(i, 0, N-1) {
		cur = ans[i];
		for (j = out[cur - 1]; j < out[cur]; j++){
			nxt = graph[j][1];
			in[nxt]--;
			if (in[nxt] == 0){
				ans[ans_idx++] = nxt;
			}
		}
	}

    // Print answer
	fp(i, 0, N-1){
		printf("%hd ", ans[i]);
	}
	return 0;
}