package com.OmarSalhe.tictac;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class TictacApplicationTests {

	@Test
	void compuerMoveTest(){
		char[] position1 = {
			'X', 'O', 'X',
			'X', 'O', 'X',
			'O', '\u0000', 'O'
		};

		char[] position2 = {
			'O', 'X', 'O',
			'X', 'O', 'X',
			'X', 'X', '\u0000'
		};
		assertEquals(new Computer(new Game(position1)).computerMove(), 7);
		assertEquals(new Computer(new Game(position2)).computerMove(), 8);
	}

	// @Test
	// void contextLoads() {
		
	// }

}
