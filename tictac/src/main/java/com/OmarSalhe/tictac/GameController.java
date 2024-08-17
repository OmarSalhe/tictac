package com.OmarSalhe.tictac;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api")

public class GameController {
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
