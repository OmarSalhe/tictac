const board = document.getElementById('board');
const cells = Array.from(document.getElementsByClassName('cell'));
const BOARD_SIZE = 9;
const PLAYER = 'X';
const squares = new Array(BOARD_SIZE).fill(null);

let errorMsg = null;
/*
    computer move:
        calls back end and gets move
        updates board
*/

// Game Logic

function makeMove(event){
    const move = cells.indexOf(event.target);
    if(isLegal(move)){
        clearError();
        updateBoard(move, PLAYER);
        // call computer move
    }
    else{
        showError('Move Error. Please press an empty square');
    }
};

function isLegal(move){
    return move < BOARD_SIZE && move >= 0 && !squares[move];
};

// Rendering

function updateBoard(move, player){
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

    // in case a message was properly handled, update its text and return
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

cells.forEach(cell => cell.addEventListener('click', makeMove));