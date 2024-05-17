import java.util.*;

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
        int[][] winningPatterns = {{0, 4, 8}, {2, 4, 6}, {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}}; // 2 diagonal + 3 horizontal + 3 vertical
        List<Integer>listOfMoves = new ArrayList<>();
        for(int i = 0; i < BOARD_SIZE; i++){
            if(this.board[i] == player){
                listOfMoves.add(i);
            }
        }
        // compare each pattern to the pattern found if same then win
        for(int[] pattern: winningPatterns){
            int count = 0;
            for(int square: pattern){
                for(int move: listOfMoves){
                    if(move == square){
                        count++;
                    }
                }
            }
            if (count == BOARD_DIMENSION){
                return true;
            }
        }
        return false;

        /* 
         * for(int i = 0, len = winningPatterns.length; i < len; i++){
            int count = 0;
            for(int j: winningPatterns[i]){
                for(int k = 0, n = listOfMoves.size(); k < n; k++){
                    if(listOfMoves.get(k) == j){
                        count++;
                    }
                }
            }
            if(count == BOARD_DIMENSION){
                return true;
            }
        }
        return false;
        */
    }

    public char[] getBoard(){
        return this.board;
    }

    public Game copy(){
        return new Game(this.board.clone());
    }
}
