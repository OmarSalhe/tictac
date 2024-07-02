import java.util.Scanner;

// Game Driver
public class TicTacToe {
    private final char PLAYER = 'X';
    private final char COMPUTER = 'O';
    private final int BOARD_SIZE = 9;
    private Game game;

    public TicTacToe(){
        this.game = new Game(new char[BOARD_SIZE]); //3x3;
    }

    public boolean checkForWinner(Player player){
        System.out.println("\n" + this.game);
        if(game.isWinner(PLAYER)){
            System.out.println(player + " Wins");
            return true;
        }
        else if(game.isWinner(COMPUTER)){
            System.out.println("Computer Wins");
            return true;
        }
        return false;
    }

    public void play(){
        boolean playerTurn = true;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter Player Name");
        Player player = new Player(in.nextLine(), this.game);
        System.out.println("\n" + this.game);

        while(!this.game.isTie()){
            if(playerTurn){
                player.playerMove();
                playerTurn = false;
            }
            else{
                Computer computer = new Computer(game);
                computer.computerMove();
                playerTurn = true;
            }
            if(checkForWinner(player)){
                break;
            }
        if(this.game.isTie()){System.out.println("The game is a tie");}
        }
        in.close();
    }

    public static void main(String[] args){
        TicTacToe game = new TicTacToe();
        game.play();
    }
}
