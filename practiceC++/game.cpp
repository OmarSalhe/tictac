#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <cstring>

#define MAX_MOVE 3

int movePredict(std::string player_move);
std::string computerMove(std::string player_move);
bool userWins(std::string player_move);
int playRSP();
int moveGuesser(std::string player_move);


int main(){
    std::string ans;
    int player_score = 0, game_count = 0;

    while(true){
        std::cout << "Lets play rock-paper-scissors!" << std::endl;
        std::cout << "input 'exit' to quit, or anything else to continue" << std::endl;
        std::cin>>ans;
        if(ans == "exit"){
            std::cout<<"GG's\n\tPlayer won: "<< player_score<<"\n\tGames played:" <<game_count <<std::endl;
            break;
        }
        player_score += playRSP();
        game_count++;
    }
    
    return 0;
}

int playRSP(){
    std::string player_move;
    std::cout<<"Rock beats Scissors, Scissors beats Paper, Paper beats Rock" << std::endl;

    std::cin>>player_move;
    std::cout<<"You played: " << player_move << std::endl;

    
    if(userWins(player_move)){
        std::cout<<"You win!" << std::endl;
        return 1;
    }
    std::cout <<"Womp womp" << std::endl;
    return 0;

}

bool userWins(std::string player_move){
    std::unordered_map<std::string, std::string> weakness;
    weakness["rock"] = "paper";
    weakness["paper"] = "scissors";
    weakness["scissors"] = "rock";

    if(weakness[computerMove(player_move)] == player_move){
        return true;
    }
    return false;
}

std::string computerMove(std::string player_move){
    std::unordered_map<int, std::string> moves;
    moves[0] = "paper"; 
    moves[1] = "scissors"; 
    moves[2] = "rock";

    std::string computer;
    if (rand() % 2 == 0){
        computer = moves[moveGuesser(player_move)];
    }
    else{
        computer = moves[rand() % MAX_MOVE];
    }
    std::cout<<"Computer plays: " << computer << std::endl;
    return computer;
}

int moveGuesser(std::string player_move){
    std::string moves[] = {"rock", "paper", "scissors"};

    std::unordered_map<std::string, int>moveHistory;
    moveHistory[moves[0]] = 1;
    moveHistory[moves[1]] = 1;
    moveHistory[moves[2]] = 1;

    for (int i = 0; i < MAX_MOVE; i++){
        if(moves[i] == player_move){
            moveHistory[moves[i]]++;
        }
    }
    double total_moves = moveHistory[moves[0]] + moveHistory[moves[1]] + moveHistory[moves[2]];
    int m_likely = 0;
    double move_avg[MAX_MOVE] = {
        moveHistory[moves[0]] / total_moves,
        moveHistory[moves[1]] / total_moves,
        moveHistory[moves[2]] / total_moves
    };
    
    for(int i = 0; i < MAX_MOVE; i++){
        if(move_avg[i] > move_avg[m_likely]){
            m_likely = i;
        }
    }
    return m_likely;
}