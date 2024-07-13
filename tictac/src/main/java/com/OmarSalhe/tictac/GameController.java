package com.OmarSalhe.tictac;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")

public class GameController {
    @PostMapping("/status")
    public ResponseEntity<Integer> checkStatus(@RequestBody char[] board){
        final int X_WIN = 1, O_WIN = 2, TIE = 0, ONGOING = -1;
        Game curState = new Game(board);
        Integer status = null;
        if(curState.isWinner('X')){
            status = X_WIN;
        }
        else if(curState.isWinner('O')){
            status = O_WIN;
        }
        if(curState.isTie()){
            status = TIE;
        }
        else{
            status = ONGOING;
        }

        return ResponseEntity.ok(status);
    }

    
    @PostMapping("/move")
    public ResponseEntity<Integer> makeMove(@RequestBody char[] board) {
        // Initialize the computer with the current game state
        Computer computer = new Computer(new Game(board));
        // Calculate the computer's move
        int move = computer.computerMove();
        // Return the move wrapped in a ResponseEntity
        return ResponseEntity.ok(move);
    }
}
