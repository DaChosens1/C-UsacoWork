//67 min
#include <iostream>
#include <fstream>
using namespace std;
 
int main(void)
{
    int N, M;
    int A[151], B[151], G[101];
    ifstream fin ("revegetate.in");
    fin >> N >> M;
    for (int i=0; i<M; i++) { 
        fin >> A[i] >> B[i];
        if (A[i] > B[i]) swap(A[i], B[i]);
    }
    fin.close();
    ofstream fout ("revegetate.out");  
    for (int i=1; i<=N; i++) {
        int g;
        for (g = 1; g <= 4; g++) 
        {
            bool ok = true;
            for (int j=0; j<M; j++) 
            {
                if (B[j] == i && G[A[j]] == g) ok = false;
            }
            if (ok) break;
            
        }
        G[i] = g;
        fout << g;
    }
    fout << "\n";
    fout.close();
    return 0;
}
