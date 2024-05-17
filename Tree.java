import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Tree{
    private Node root;

    public Tree(Node root){
        System.out.println("We made a tree!");
        this.root = null;
        insert(root);
    }

    private void insert(Node gameState){
        if(this.root == null){
            this.root = gameState;
            gameState.addChild();
        }
        insertRecursively(gameState);
    }
    
    private void insertRecursively(Node gameState){
        if(gameState == null){
            return;
        }
        List<Node>possiblePositions = gameState.getPossibleGameStates();
        for(Node position: possiblePositions){
            position.addChild();
            insertRecursively(position);
        }
    }  
}

class Node{  
    private Game curGameState; // current game state
    private char player;
    private List<Node>possibleGameStates; //possible states
    private int eval;

    public Node(Game gameState, char player){
        this.curGameState = gameState;
        this.player = player;
        this.possibleGameStates = new ArrayList<>();
        //for each move in the list of possible moves I want to play it in a new game
    }

    public String toString(){
        return this.curGameState + "\n" + this.eval;
    }

    public void setEval(int eval){
        this.eval = eval;
    }

    public int getEval(){
        return this.eval;
    }

    public List<Node> getPossibleGameStates(){
        return this.possibleGameStates;
    }

    public Game getGameState(){
        return this.curGameState;
    }

    public void addChild(){
        final char COMPUTER = 'O';
        final char PLAYER = 'X';
        char altPlayer;
        if(this.player == COMPUTER){
            altPlayer = PLAYER;
        }
        else{
            altPlayer = COMPUTER;
        }
        Game[] possiblePositions = newPositions();
        if(possiblePositions != null){
            for(int i = 0, n = possiblePositions.length; i < n; i++){
                this.possibleGameStates.add(new Node(possiblePositions[i], altPlayer));
            }
        }
    }

    private Game[] newPositions(){
        int[] possibleMoves = generateMoves();
        int numOfMoves = possibleMoves.length;
        if(numOfMoves == 0){
            return null;
        }
        Game[] newPos = new Game[numOfMoves];
        for(int i = 0; i < numOfMoves; i++){
            newPos[i] = this.curGameState.copy();
            newPos[i].playMove(possibleMoves[i], player);
        }
        return newPos;
    }

    private int[] generateMoves(){
        final char EMPTY = ' ';
        final int BOARD_SIZE = 9;

        int[] tmp = new int[BOARD_SIZE];
        char[] board = curGameState.getBoard();
        int numOfMoves = 0;
        for(int i = 0; i < BOARD_SIZE; i++){
            if(board[i] == EMPTY){
                tmp[numOfMoves] = i;
                numOfMoves++;
            }
        }
        
        return Arrays.copyOf(tmp, numOfMoves);
    }

}
