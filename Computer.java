import java.util.*;

public class Computer {
    private final int SIZE = 9;
    private final char EMPTY = ' ';
    private final char PLAYER1 = 'O';
    private final char PLAYER2 = 'X';

    private Game game;
    private GameTree tree;

    public Computer(Game game){
        this.game = game;
    }

    public int[] moveGen(){
        int[] tmp = new int[SIZE];
        char[] board = game.getBoard();
        int count = 0;
        for(int i = 0; i < SIZE; i++){
            if(board[i] == EMPTY){
                tmp[count] = i;
                count++;
            }
        }
        return Arrays.copyOf(tmp, count);
    }

    public int makeMove(int move){
        return move;
    }
}

//TO DO

/* Generate Moves
*  List out each possible move
*  Evaluate each move
*  Interact with Board
*  Make move
*    
*/
