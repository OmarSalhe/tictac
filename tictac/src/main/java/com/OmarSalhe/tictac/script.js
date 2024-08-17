const board = document.getElementById('board');
const cells = Array.from(document.getElementsByClassName('cell'));
const BOARD_SIZE = 9;
const PLAYER = 'X';
const COMPUTER = 'O';
const squares = new Array(BOARD_SIZE).fill(null);

let errorMsg = null;

// Game Logic
/**
 * Contains:
 *  Move validation
 *  client interactions
 */

function clientMove(event){
    const move = cells.indexOf(event.target);
    if(isLegal(move)){
        clearError();
        updateUI(move, PLAYER);
        setTimeout(computerMove, 1000);
    }
    else{
        showError('Move Error. Please press an empty square');
    }
};

function isWinner(player){
    const winningPatterns = [
        [0, 4, 8], 
        [2, 4, 6], 
        [0, 1, 2], 
        [3, 4, 5], 
        [6, 7, 8], 
        [0, 3, 6], 
        [1, 4, 7], 
        [2, 5, 8]
    ];

    for(let pattern of winningPatterns){
        const ROW = 3;
        let count = 0;
        for(let i = 0; i < ROW; i++){
            if(squares[pattern[i]] === player){
                count++;
            }
        }
        if(count === ROW){
            return true;
        }
    }
    return false;
};

function isTie(){
    for(let cell of squares){
        if(cell){
            return false;
        }
    }
    return !isWinner(PLAYER) && !isWinner(COMPUTER);
};

function isLegal(move){
    return move < BOARD_SIZE && move >= 0 && !squares[move];
};

function checkWinLocally(){
    if(isWinner(PLAYER)){
        showMessage("Congrats! You Win!");
        //verifyWinnerRemotely(PLAYER);
    }
}

// Back-end Calls
/**
 * Contains requests to server for:
 *  validating game status
 *  retrieving computer moves
 */
// function verifyWinnerRemotely(winner){
//     fetch('https://localhost:8080/api/status', {
//         method: 'POST',
//         headers: {
//             'Content-Type': 'application/json'
//         },
//         body: JSON.stringify(squares)
//       })
//         .then(response => {
//           if (!response.ok) {
//             throw new Error('Network response was not ok');
//           }
//           return response.json();
//         })
//         .then(status => {
//             if(status == winner){
//                 console.log('Server confirms win: ', winner);
//             }
//             else{
//                 console.warn('Server denies win: ', winner);
//                 showError('Server Validation Error Win denied');
//             }
//         })
//         .catch(error => {
//           console.error('There has been a problem with your fetch operation:', error);
//         });
// };

function computerMove(){
    fetch('https://localhost:8080/api/move', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json'
    },
    body: JSON.stringify(squares)
  })
    .then(response => {
      if (!response.ok) {
        throw new Error('Network response was not ok');
      }
      return response.json();
    })
    .then(move => {
      updateUI(move, COMPUTER);
    })
    .catch(error => {
      console.error('There has been a problem with your fetch operation:', error);
    });
};

// Rendering
/**
 * Contains functions for:
 *  updating UI
 *  interacting with board representations
 */

function updateUI(move, player){
    squares[move] = player;
    cells[move].textContent = player;
};

function clearBoard(){
    for(let i = 0; i < BOARD_SIZE; i++){
        cells[i].innerHTML = '';
        squares[i] = null;
    }
};

function clearError(){
    const errorContainer = document.getElementById('error-container');
    while(errorMsg && errorContainer.contains(errorMsg)){
        errorContainer.removeChild(errorMsg);
        errorMsg = null;
    }
};

function showError(msg){
    clearError();
    const errorContainer = document.getElementById('error-container');

    // in the case a message was not properly handled, update its text and return
    if(errorMsg){
        errorMsg.textContent = msg;
        return;
    }

    errorMsg = document.createElement('div')
    errorMsg.textContent = msg;
    errorMsg.classList.add('err-msg');
    errorContainer.appendChild(errorMsg);

    // initiates animation and removes error message from DOM after 1 second(s)
    setTimeout(() => {
        errorMsg.classList.add('fade-out');
        errorMsg.addEventListener('transitionend', clearError);
    }, 1000);
};

cells.forEach(cell => cell.addEventListener('click', clientMove));