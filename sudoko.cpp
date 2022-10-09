#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
     bool isRow(vector<vector<char>>& board,int row,char num,int COLS){
        for(int i =0; i < COLS;i++){
            if(board[row][i] == num) return false;
        }
        return true;
    }
    bool isCol(vector<vector<char>>& board,int col,char num,int ROWS){
        for(int i =0;i < ROWS;i++){
            if(board[i][col] == num) return false;
        }
        return true;
    }
    bool isGrid(vector<vector<char>>& board,int row,int col,char num,int ROWS,int COLS){
        //starting row and starting column of that specific 3 x 3 grid 
        int rowfactor = row - (row%3);
        int colfactor = col - (col%3);
        for(int i =0 ; i < 3;i++){
            for(int j =0; j < 3;j++){
                int newrow = rowfactor + i;
                int newcol = colfactor + j;
                if(board[newrow][newcol] == num) return false;
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& board,int row,int col,char num,int ROWS,int COLS){
        //1.check in row Each of the digits 1-9 must occur exactly once in each row.
        //2.check in col Each of the digits 1-9 must occur exactly once in each column.
        //3.check in grid Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
        if(isRow(board,row,num,COLS) && isCol(board,col,num,ROWS) && isGrid(board,row,col,num,ROWS,COLS)){
            return true;
        }
        return false;
    }
    bool isEmpty(vector<vector<char>>& board,int ROWS,int COLS,int &row,int &col){
        for(int i =0 ; i < ROWS;i++){
            for(int j =0; j < COLS;j++) {
                if(board[i][j] == '.') {
                    row  = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }

    bool solve(vector<vector<char>>& board,int ROWS,int COLS){
        //base case when there is no empty space in board 
        int row ,col;
        if(!isEmpty(board,ROWS,COLS,row,col)) return true;
        for(int i =1; i <= 9;i++){
            bool isPlacable = check(board,row,col,(i+48),ROWS,COLS);
            if(isPlacable){
                board[row][col] = (char)(i+48);
                if(solve(board,ROWS,COLS)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        solve(board,ROWS,COLS);
    }
};