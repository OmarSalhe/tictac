import java.util.List;

public class Computer {
    private final char COMPUTER = 'O';
    private final char PLAYER = 'X';
    private final int MAX = 10;
    private final int MIN = -10;
    private final int TIE = 0;

    private Game game;
    private Tree tree;
    private Node currentPosition;

    public Computer(Game game){
        this.game = game;                                                                                                                                                                                                                                                                                                                                                                          
        this.currentPosition = new Node(game, COMPUTER);
        this.tree = new Tree(currentPosition);
    }

    public void computerMove(){
        int bestEval = minimaxAlgo(this.currentPosition, true);
        List<Node>potentialGameStates = this.currentPosition.getPossibleGameStates();
        for(Node gameState: potentialGameStates){
            if(gameState.getEval() == bestEval){
                this.game.playMove(findMove(this.currentPosition, gameState), COMPUTER);
            }
        }
    }

    private int findMove(Node root, Node child){
        char[] currentBoard = root.getGameState().getBoard();
        char[] bestBoard = child.getGameState().getBoard();
        for(int i = 0, len = currentBoard.length; i < len; i++){
            if(currentBoard[i] != bestBoard[i]){
                System.out.println(i);
                return i;
            }
        }
        return -1;
    }

    private int minimaxAlgo(Node position, boolean maximizingPlayer){
        if(gameIsOver(position.getGameState())){
            System.out.println(position);
            return evaluation(position.getGameState());
        }
        List<Node>possibleGameStates = position.getPossibleGameStates();
        if(maximizingPlayer){
            int maxEval = MIN;
            for(Node gameState: possibleGameStates){
                int eval = minimaxAlgo(gameState, false);
                maxEval = max(maxEval, eval);
            }
            position.setEval(maxEval);
            return maxEval;
        }
        else{
            int minEval = MAX;
            for(Node gameState: possibleGameStates){
            int eval = minimaxAlgo(gameState, true);
            minEval = min(minEval, eval);
            }
            position.setEval(minEval);
            return minEval;
        }
    }

    public int max(int x, int y){
        return x > y? x : y;
    }

    public int min(int x, int y){
        return x < y? x : y;
    }

    public int evaluation(Game position){
        if(position.isWinner(COMPUTER)){
            return MAX;
        }
        else if(position.isWinner(PLAYER)){
            return MIN;
        }
        return TIE;
    }

    public boolean gameIsOver(Game game){
        return game.isWinner(PLAYER) || game.isWinner(COMPUTER) || game.isTie();
    }
}
