import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Tree{
    private Node root;

    public Tree(Node root){
        this.root = null;
        insert(root, 0);
    }

    private void insert(Node gameState, int depth){
        if(this.root == null){
            this.root = gameState;
            this.root.setDepth(depth);
            gameState.addChild();
        }
        insertRecursively(gameState, depth + 1);
    }

    private void insertRecursively(Node gameState, int depth){
        if(gameState == null){
            return;
        }
        List<Node> possiblePositions = gameState.getPossibleGameStates();
        for(Node position: possiblePositions){
            position.addChild();
            position.setDepth(depth);
            insertRecursively(position, depth + 1);
        }
    }  
}

class Node{  
    private Game curGameState;
    private char player;
    private List<Node>possibleGameStates;
    private int eval;
    private int depth;

    public Node(Game gameState, char player){
        this.curGameState = gameState;
        this.player = player;
        this.possibleGameStates = new ArrayList<>();
    }

    public String toString(){
        return this.curGameState + "\n" + "Eval: " + this.eval;
    }

    public void setDepth(int depth){
        this.depth = depth;
    }

    public int getDepth(){
        return this.depth;
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

    public Node[] getSortedPossibleGameStates(){
        Node[] posArr = this.possibleGameStates.toArray(new Node[0]);
        return mergeSort(0, posArr.length - 1, posArr);
    }

    public Game getGameState(){
        return this.curGameState;
    }
    
    private Node[] mergeSort(int start, int end, Node[] posArr){
        if(start == end){
            return new Node[]{posArr[start]};
        }
        int mid = (end + start) / 2;
        Node[] A = mergeSort(start, mid, posArr);
        Node[] B = mergeSort(mid + 1, end, posArr);

        return merge(A, B);
    }

    private Node[] merge(Node[] A, Node[] B){
        int aLen = A.length;
        int bLen = B.length;
        int i = 0, j = 0, l = 0;
        Node[] merged = new Node[aLen + bLen];

        while(i < aLen && j < bLen){
            if(A[i].getEval() >= B[j].getEval()){
                merged[l++] = A[i++];
            }
            else{
                merged[l++] = B[j++];
            }
        }
        while(i < aLen){
            merged[l++] = A[i++];
        }
        while(j < bLen){
            merged[l++] = B[j++];
        }
        return merged;
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
