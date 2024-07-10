const board = document.getElementById('board');
const cell = Array.from(document.getElementsByClassName('cell'));
const PLAYER = 'X';

let squares = new Array(BOARD_SIZE).fill(null);

function makeMove(event){
    const err = document.getElementById('err-msg');
    const move = cell.indexOf(event.target);
    if(isLegal(move)){
        clearError();
        updateBoard(move, PLAYER);
        // call computer move
    }
    else{
        showError('Square is already occupied. Please press an empty square.');
    }
};

/*
    computer move:
        calls back end and gets move
        updates board
*/

// Game Logic

function isLegal(move){
    return move < BOARD_SIZE &&  !squares[move];
};

// Rendering

function updateBoard(move, player){
    squares[move] = player;
    cell[move].textContent = squares[move];
};

function clearBoard(){
    for(let i = 0; i < BOARD_SIZE; i++){
        cell[i].innerHTML = '';
        squares[i] = EMPTY;
    }
};

function clearError(){
    const error = document.getElementById('error-container');
    while(error.firstChild){
        error.remove(error.firstChild);
    }
};
function showError(msg){
    clearError();
    const errorContainer = document.getElementById('error-container');
    const errorMsg = document.createElement('div')
    errorMsg.textContent(msg);
    errorMsg.classList.add('err-msg')
    errorContainer.appendChild(errorMsg)

    // initiates animation and removes error message from DOM after 3 seconds
    setTimeout(() => {
        errorMsg.classList.add('fade-out');
        errorMsg.addEventListener('transitionend', () => {
            if(errorContainer){
                errorContainer.removeChild(errorMsg);
            }
        })

    }, 3000);
};