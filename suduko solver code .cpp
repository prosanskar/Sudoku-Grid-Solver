#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


bool check(vector<vector<char> > &A,int k,int row,int col){
    int n=A.size();
    for(int i=0;i<n;++i){
        if(A[i][col]==k+'0')return false; /* Checking the presence of the value k in the same column*/
        if(A[row][i]==k+'0')return false; /* Checking the presence of the value k in the same column*/
        int x=3*(row/3)+i/3;         /* Checking the presence of the value k in the same 3*3 square */
        int y=3*(col/3)+i%3;
        if(A[x][y]==k+'0')return false;
    }
    return true;
}

bool solve(vector<vector<char>> &A){
   int n=A.size();
   for(int i=0;i<n;++i){
       for(int j=0;j<n;++j){
           if(A[i][j]=='.'){
               for(int val=1;val<10;++val){
                   if(check(A,val,i,j)){
                       A[i][j]=val+'0';
                       bool possible=solve(A); /* Checking whether the sudoku is solvable after inserting value as val*/
                       if(possible)return true;
                       else{
                           A[i][j]='.'; /* Backtracking */
                       }
                   }
               }
               return false;
           }
       }
   }
   return true;
}

void solveSudoku(vector<vector<char> > &A) {
    int n=A.size();
    solve(A);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> A(n,vector<char>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cin>>A[i][j];  /* Taking input */
    }
    solveSudoku(A);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<A[i][j]<<" ";  /* Printing the solved Sudoku */
        cout<<endl;
    }
    return 0;
}

