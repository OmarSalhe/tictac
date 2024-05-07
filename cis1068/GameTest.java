//Omar Salhe
//Simple tests for the Game program previously mentioned

import static org.junit.Assert.*;
import org.junit.Test;
public class GameTest {
    String move[] = {"Fjallbo", "Oxberg", "Vittsjo", "Jattesta", "Ekenabben"}; // legal moves in-game
    Game Game = new Game(); // calls game program for testing

    @SuppressWarnings("static-access")
    @Test
    public void userWinsTest(){
        //user wins
        assertTrue(Game.userWins(move[0], move[3]));
        assertTrue(Game.userWins(move[0], move[2]));        
        assertTrue(Game.userWins(move[1], move[4]));
        assertTrue(Game.userWins(move[1], move[0]));           
        assertTrue(Game.userWins(move[2], move[1]));
        assertTrue(Game.userWins(move[2], move[3]));
        assertTrue(Game.userWins(move[3], move[4]));
        assertTrue(Game.userWins(move[3], move[1]));
        assertTrue(Game.userWins(move[4], move[1]));
        assertTrue(Game.userWins(move[4], move[2]));

        // computer wins
        assertFalse(Game.userWins(move[0], move[4]));
        assertFalse(Game.userWins(move[0], move[1]));        
        assertFalse(Game.userWins(move[1], move[3]));
        assertFalse(Game.userWins(move[1], move[2]));           
        assertFalse(Game.userWins(move[2], move[0]));
        assertFalse(Game.userWins(move[2], move[4]));
        assertFalse(Game.userWins(move[3], move[2]));
        assertFalse(Game.userWins(move[3], move[0]));
        assertFalse(Game.userWins(move[4], move[0]));
        assertFalse(Game.userWins(move[4], move[3]));
        
        // ties
        assertFalse(Game.userWins(move[0], move[0]));
        assertFalse(Game.userWins(move[1], move[1]));
        assertFalse(Game.userWins(move[2], move[2]));
        assertFalse(Game.userWins(move[3], move[3]));
        assertFalse(Game.userWins(move[4], move[4]));
    }

    @SuppressWarnings("static-access")
    @Test
    public void isValidMoveTest(){
        // Legal game moves
        assertTrue(Game.isValidMove(move[0]));
        assertTrue(Game.isValidMove(move[1]));
        assertTrue(Game.isValidMove(move[2]));
        assertTrue(Game.isValidMove(move[3]));
        assertTrue(Game.isValidMove(move[4]));

        // Illegal game moves
        assertFalse(Game.isValidMove("pizza")); // foreign word
        assertFalse(Game.isValidMove("fjallbo")); // improper capitalization
    }
}