//Omar Salhe
//Basic program that engages user in a game of baggebo against a computer and keeps track of score.

import java.util.*;

public class Game {
    public static void main(String[] args){
        playBaggebo();
    }

    public static void playBaggebo(){ // asks user to engage in a game of baggebo
        int player_score = 0, game_count = 0;
        char player;

        System.out.println("Fun Fact: to pass the time during long winters, the ancient Nordic people would play the two-player game of Baggebo.\n");
        while(true){
            System.out.print("Would you like to play a game of Baggebo? (y/n): ");
            player = userInput().charAt(0);
            if (player == 'n' || player == 'N'){
                if (game_count < 1){
                    System.out.println("\nThat's too bad...\nNo games played");
                } 
                else{
                    System.out.println("Well, I had fun");
                    System.out.println("Stats:\n   Games played: " + game_count + "\n   Player wins: " + player_score + "\n   Computer wins: " + (game_count - player_score));
                }
                break;
            }
            else if (player == 'y' || player == 'Y'){
                player_score += baggeboGame();
                game_count++;
            }
            else{
                System.out.println("Invalid input. y or n");
            }
        }
    }

    public static int baggeboGame(){ // method for actual gameplay
        int player_score = 0;
        System.out.println("In the game of Baggebo, players choose a move_choice, which may be either Fjallbo, Oxberg, Vittsjo,\nJattesta, or Ekenabben. The rules are:");
        System.out.println("Ekenabben beats Vittsjo and Fjallbo");
        System.out.println("Vittsjo beats Oxberg and Jattesta");
        System.out.println("Oxberg beats Ekenabben and Fjallbo");
        System.out.println("Fjallbo Beats Jattesta and Vittsjo");
        System.out.println("Jattesta beats Ekenabben and Oxberg");

        System.out.println("Enter a move, exactly as shown above.");
        String player_move = "Empty";
        player_move = checkUserMove(player_move);

        if(userWins(player_move, computerMove())){
            System.out.println("*Cue fanfare* You win");
            player_score++;
        }
        else {
            System.out.println("Womp Womp");
            System.out.println("Ai Overlord has taken over. Please hero...try again.");
        }
        return player_score;
    }
    
    public static String checkUserMove(String player_move){ // ensures user moves is valid
        player_move = userInput();
        while (!isValidMove(player_move)){
            System.out.println("Invalid move. Please choose between Fjallbo, Oxberg, Vittsjo, Jattesta, or Ekenabben and exactly as shown");
            player_move = userInput();
        }
        return player_move;
    }

    public static boolean userWins(String player_move, String computer_move){ // game logic
        String move[] = {"Fjallbo", "Oxberg", "Vittsjo", "Jattesta", "Ekenabben"};

        System.out.println("You played " + player_move);
        System.out.println("Computer played " + computer_move);

        if (player_move.compareTo(move[0]) == 0){
            if (computer_move.compareTo(move[3]) == 0 || computer_move.compareTo(move[2]) == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else if (player_move.compareTo(move[1]) == 0){
            if (computer_move.compareTo(move[4]) == 0 || computer_move.compareTo(move[0]) == 0){
                return true;
            }
            else{
                return false;
            }        
        }
        else if (player_move.compareTo(move[2]) == 0){
            if (computer_move.compareTo(move[1]) == 0 || computer_move.compareTo(move[3]) == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else if (player_move.compareTo(move[3]) == 0){
            if (computer_move.compareTo(move[4]) == 0 || computer_move.compareTo(move[1]) == 0){
                return true;
            }
            else{
                return false;
            }        
        }
        else if (player_move.compareTo(move[4]) == 0){
            if (computer_move.compareTo(move[1]) == 0 || computer_move.compareTo(move[2]) == 0){
                return true;
            }
            else{
                return false;
            }
        }
        return false; // accounts for any deviating outcomes
    }

    public static String computerMove(){ // generates computer moves at random
        final int MAX_MOVE = 5;
        Random move = new Random();
        String move_choice[] = {"Fjallbo", "Oxberg", "Vittsjo", "Jattesta", "Ekenabben"};

        int computer = move.nextInt(MAX_MOVE);

        return move_choice[computer];
    }

    public static boolean isValidMove(String player_move){ // checks if user plays a valid move
        String moves[] = {"Fjallbo", "Oxberg", "Vittsjo", "Jattesta", "Ekenabben"};

        for(String move : moves ){
            if (move.equals(player_move)){ 
                return true;
            }
        }
        return false;
    }

    public static String userInput(){ // takes user input
        Scanner input = new Scanner(System.in);
        String user_input = input.next();

        input.close();
        return user_input;
    }
}
    

/*
CHOICES = Fjallbo, Oxberg, Vittsjo, Jattesta, or Ekenabben
    
GAME RULES -> function
 * 4 Ekenabben beats Vittsjo, Fjallbo
 * 2 Vittsjo beats Oxberg, Jattesta
 * 1 Oxberg beats Ekenabben, Fjallbo
 * 0 Fjallbo Beats Jattesta, Vittsjo
 * 3 Jattesta beats Ekenabben, Oxberg
 */

/*
 * The rules should be printed to the screen
 * The user is asked if they'd like to play a round -> main
 *      if they choose 'y', a round is played -> game function
 *      if they choose 'n', the program ends -> end
 * Until the user has chosen to quit, another round is played. -> anyother response = y
 
 * In a round of play:
 *      the user is asked to enter a move_choice, which may be either Fjallbo, Oxberg, Vittsjo, Jattesta, or Ekenabben. The program should continue to prompt the user until a valid move_choice is entered.
 *      The computer makes a move_choice at random. (Hint: remember how we generated random numbers in class.) -> computer function
 *      Determine the winner ->  game function return 1(win) or 0(lose)
 *      The program prints the computer's move_choice, the user's move_choice, and who is the winner of this round
 *      The user is asked if they'd like to continue. -> main
 *      When the user has decided to quit the game, the program prints the number of:
 *      rounds played, times the user won, times the computer won
 */

/*
 * main
 *  while true
 *   play? y/n
 *   if n -> print game, player, game-player
 *   else -> game funct game++ player+=player(return val)
 * 
 * game funct
 *  print rules
 *  user input
 *  computer input
 *  call logic funt
 *  if win -> player++ print u win
 *  else -> womp womp
 *  return player
 * 
 * computer funct
 *  random int 0, 4
 *  switch 0-4 = choices
 *  return choice
 */