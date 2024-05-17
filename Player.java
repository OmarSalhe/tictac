import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Player {
    private String name;
    private Game game;

    private final char PLAYER = 'X';

    public Player(String name, Game game){
        this.name = name;
        this.game = game;
    }

    public String toString(){
        return this.name;
    }

    public void playerMove(){
        System.out.println("Enter Row and Column");
        int validMove = -1;
        do{
            validMove = playerInputLoop();
        }
        while(validMove < 0);
        game.playMove(validMove, PLAYER);
    }

    private int playerInputLoop(){
        Scanner in = null;
        Scanner inputtedMove = null;
        try{
            in = new Scanner(System.in);
            inputtedMove = new Scanner(in.nextLine());
            int row = inputtedMove.nextInt() - 1;
            int col = inputtedMove.nextInt() - 1;
            int move = row + 3 * col;
            if(moveValidation(row, col, move)){
                return move;
            }
            System.err.println("BOTH Row and Column values MUST be from 1 to 3");
        }
        catch(InputMismatchException e){
            System.err.println("Either: Input both Row and Column as TWO NUMBERS SEPARATED by a space");
        }
        catch(NoSuchElementException f){
            System.err.println("Premature System.in Scanner closing");
        }
        finally{
            inputtedMove.close();
        }
        return -1;
    }

    private boolean moveValidation(int row, int col, int move){
        final int BOARD_SIZE = 9;
        final char EMPTY = ' ';
        final int DIMENSIONS = 3;
        return (0 > row || row < DIMENSIONS) && (0 > col || col < DIMENSIONS) && move < BOARD_SIZE && game.getBoard()[move] == EMPTY;
        // row and col between 0-3 AND move must be between 0-9 AND the slot gotta be empty
    }
} 

