#include <iostream>
#include <fstream>
using namespace std;
 
int N, incoming[101], outgoing[101];
 
int main(void)
{
	ifstream fin ("factory.in");
	fin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		fin >> a >> b;
		outgoing[a]++;
		incoming[b]++; 
	}
	
	ofstream fout ("factory.out");
	int answer = -1;
	for (int i = 1; i <= N; i++) {
		if (outgoing[i] == 0 and answer != -1) 
		{
			answer = -1;
			break;
		}
		if (outgoing[i] == 0) 
		{
			answer = i;
		}
	}
	fout << answer << "\n";
	return 0;
}