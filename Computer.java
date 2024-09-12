import java.util.List;
import java.lang.Math;

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
        int bestEval = minimaxAlgo(this.currentPosition, true, MIN, MAX);
        List<Node> potentialGameStates = this.currentPosition.getPossibleGameStates();
        for(Node gameState: potentialGameStates){
            if(gameState.getEval() == bestEval){
                this.game.playMove(findMove(this.currentPosition, gameState), COMPUTER);
                return;
            }
        }
    }

    private int findMove(Node root, Node child){
        char[] currentBoard = root.getGameState().getBoard();
        char[] bestBoard = child.getGameState().getBoard();
        for(int i = 0, len = currentBoard.length; i < len; i++){
            if(currentBoard[i] != bestBoard[i]){
                return i;
            }
        }
        return -1;
    }

    private int minimaxAlgo(Node position, boolean maximizingPlayer, int alpha, int beta){
        if(gameIsOver(position.getGameState())){
            int eval = evaluate(position);
            position.setEval(eval);
            return eval;
        }
        List<Node> possibleGameStates = position.getPossibleGameStates();
        if(maximizingPlayer){
            int maxEval = MIN;
            for(Node gameState: possibleGameStates){
                int eval = minimaxAlgo(gameState, false, alpha, beta);
                maxEval = Math.max(maxEval, eval);
                alpha = Math.max(alpha, eval);
                // if better move was found earlier on
                if(beta <= alpha){
                    break;
                }
            }
            position.setEval(maxEval);
            return maxEval;
        }
        else{
            int minEval = MAX;
            for(Node gameState: possibleGameStates){
            int eval = minimaxAlgo(gameState, true, alpha, beta);
            minEval = Math.min(minEval, eval);
            beta = Math.min(beta, eval);
            if(beta <= alpha){
                break;
            }
            }
            position.setEval(minEval);
            return minEval;
        }
    }

    public int evaluate(Node position){
        if(position.getGameState().isWinner(COMPUTER)){
            return MAX - position.getDepth();
        }
        else if(position.getGameState().isWinner(PLAYER)){
            return MIN - position.getDepth();
        }
        return TIE;
    }
    public boolean gameIsOver(Game game){
        return game.isWinner(PLAYER) || game.isWinner(COMPUTER) || game.isTie();
    }
}
