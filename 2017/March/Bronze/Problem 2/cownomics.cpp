//29 minutes
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int N, M;
string spotty[100], plain[100];

int test_location(int j)
{
  int found_cow[2][4] = {0};
  for (int i=0; i<N; i++) {
    if (spotty[i][j] == 'A') found_cow[0][0] = true;
    if (spotty[i][j] == 'C') found_cow[0][1] = true;
    if (spotty[i][j] == 'G') found_cow[0][2] = true;
    if (spotty[i][j] == 'T') found_cow[0][3] = true;
  }
  for (int i=0; i<N; i++) {
    if (plain[i][j] == 'A') found_cow[1][0] = true;
    if (plain[i][j] == 'C') found_cow[1][1] = true;
    if (plain[i][j] == 'G') found_cow[1][2] = true;
    if (plain[i][j] == 'T') found_cow[1][3] = true;
  }
  for (int i = 0; i < 4; ++i) {
    if (found_cow[0][i] && found_cow[1][i]) return false;
  }
  return true;
}

int main(void)
{
  ifstream fin ("cownomics.in");
  ofstream fout ("cownomics.out");
  fin >> N >> M;
  for (int i=0; i<N; i++) fin >> spotty[i];
  for (int i=0; i<N; i++) fin >> plain[i];
  int answer = 0;
  for (int j=0; j<M; j++) 
    if (test_location(j)) answer++;
  fout << answer << "\n";
  return 0;
}
