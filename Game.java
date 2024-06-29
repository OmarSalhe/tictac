import java.util.*;

//Game Logic
public class Game{
    private char[] board;
    private final char PLAYER = 'X';
    private final char COMPUTER = 'O';
    private final char EMPTY = ' ';
    private final int BOARD_SIZE = 9;
    private final int BOARD_DIMENSION = 3; // 3x3

    public Game(char[] board){
        this.board = board;
        if(boardIsEmpty()){
            emptyBoard();
        }
    }
    private void emptyBoard(){
        for(int i = 0; i < BOARD_SIZE; i++){
            this.board[i] = EMPTY;
        }
    }
    
    private boolean boardIsEmpty(){
        return Arrays.binarySearch(this.board, '\u0000') > 0;
    }
    
    public String toString(){
        String boardString = "";
        for(int i = 0, len = BOARD_SIZE; i < len; i++){
            if(i % BOARD_DIMENSION == 0){
                boardString += "\n";
            }
            boardString += "[" + this.board[i] + "]";
        }
        return boardString;
    }
    
    public void playMove(int move, char player){
        this.board[move] = player;
    }

    public boolean isTie(){
        for(char square: this.board){
            if(square == EMPTY){
                return false;
            }
        }
        return !isWinner(PLAYER) && !isWinner(COMPUTER);
    }

    public boolean isWinner(char player){
        int[][] winningPatterns = {{0, 4, 8}, {2, 4, 6}, {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}};
         for(int[] pattern: winningPatterns){
            int count = 0;
            for(int i = 0; i < BOARD_DIMENSION; i++){
                if(this.board[pattern[i]] == player){
                    count++;
                }
            }
            if(count == BOARD_DIMENSION){
                return true;
            }
        }
        return false;
    }

    public char[] getBoard(){
        return this.board;
    }

    public Game copy(){
        return new Game(this.board.clone());
    }
}
