import java.util.*;

public class TicTacToe{
    private char[] board;

    private final char PLAYER = 'X';
    private final char GPT = 'O';
    private final char EMPTY = ' ';
    private final int SIZE = 3;
    private final int WIN = 3;

    public TicTacToe(){
        board = new char[SIZE*SIZE]; // 3x3
        for(int i = 0, len = board.length; i < len; i++){
            board[i] = EMPTY;
        }
    }

    public String toString(){
        String boardString = "";

        for(int i = 0, len = board.length; i < len; i++){
            if(i % SIZE == 0){
                boardString += "\n";
            }
            boardString += "[" + this.board[i] + "]";
        }
        return boardString;
    }

    public boolean validMove(int move, char player){
        return move < this.board.length && this.board[move] == EMPTY;
    }

    public void playMove(int move, char player){
        this.board[move] = player;
    }
    public boolean isTie(){
        return Arrays.binarySearch(this.board, EMPTY) <= 0;
    }

    public boolean isWinner(char player){
        int[][] winningPattern = {{0, 4, 8}, {2, 4, 6}, {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}}; // 2 diagonal + 3 horizontal + 3 vertical
        List<Integer>listOfMoves = new ArrayList<>();
        for(int i = 0, len = board.length; i < len; i++){
            if(this.board[i] == player){
                listOfMoves.add(i);
            }
        }
        // compare each pattern to the pattern found if same then win
        for(int i = 0, len = winningPattern.length; i < len; i++){
            int count = 0;
            for(int j: winningPattern[i]){
                for(int k = 0, n = listOfMoves.size(); k < n; k++){
                    if(listOfMoves.get(i) == j){
                        count++;
                    }
                }
            }
            if(count == WIN){
                return true;
            }
        }
        return false;
    }

    public void play(){
        boolean playerTurn = true;
        Scanner in = new Scanner(System.in);
        while(!isTie()){
            if(playerTurn){
                do {
                    System.out.println("Enter: Row and Column");
                    Scanner move = new Scanner(in.nextLine());

                    int playerMove = move.nextInt() + move.nextInt();
                    if(validMove(playerMove, PLAYER)){
                        this.board[playerMove] = PLAYER;
                        playerTurn = false;
                        break;
                    }
                    move.close();
                } while(true);
            }
            else{
                //computerMove = computer move
                playerTurn = true;
            }
            if(isWinner(PLAYER)){
                System.out.println("Player Wins");
                break;
            }
            else if(isWinner(GPT)){
                System.out.println("Computer Wins");
                break;
            }
        }
        in.close();
    }
}
