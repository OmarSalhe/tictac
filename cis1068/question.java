public class question {
    protected int points;
    protected int difficulty;
    protected String questionText;
    protected final int ANSWER_SPACE  = 4;
    protected final int MAX_DIFF = 5;
    protected final int MIN_DIFF = 1;

    public question(int points, int difficulty, String questionText){
        this.points = points;
        this.questionText = questionText;
        if (difficulty > MAX_DIFF || difficulty < MIN_DIFF){
            this.difficulty = MIN_DIFF;
        }
        else{
            this.difficulty = difficulty;
        }
    }

    public String toString(){
        String spaceForAnswer = "";
        for(int i = 0; i < ANSWER_SPACE; i++){
            spaceForAnswer += "_";
        }
        return spaceForAnswer + " " + this.questionText + " " + this.points + "pts Difficulty: " + this.difficulty + " / " + this.MAX_DIFF;
    }

    public int getPoints(){
        return this.points;
    }
}

class objectiveQuestion extends question {
    protected String correctAnswer;

    public objectiveQuestion(int points, int difficulty, String questionText, String correctAnswer){
        super(points, difficulty, questionText);
        this.correctAnswer = correctAnswer;
    }

    public String toStringCorrect(){
        String spaceForAnswer = "";
        for(int i = 0; i < this.ANSWER_SPACE / 2; i++){
            spaceForAnswer += "_";
        }
        return spaceForAnswer + this.correctAnswer + spaceForAnswer + " " + this.questionText + " " + this.points + "pts Difficulty: " + this.difficulty + " / " + this.MAX_DIFF + "\n";
    }
}

class fillInTheBlankQuestion extends objectiveQuestion{
    public fillInTheBlankQuestion(int points, int difficulty, String questionText, String correctAnswer){
        super(points, difficulty, questionText, correctAnswer); 
    }
}

class multipleChoiceQuestion extends objectiveQuestion {
    private String[] possibleAnswer;

    public multipleChoiceQuestion(int points, int difficulty, String questionText, String[] possibleAnswer, String correctAnswer){
        super(points, difficulty, questionText, correctAnswer);
        this.possibleAnswer = possibleAnswer;
    }

    @Override
    public String toString(){
        String listOfAns = "";
        for(int i = 0; i < this.possibleAnswer.length; i++){
            listOfAns += (i + 1) + ". " + this.possibleAnswer[i] + "\n";
        }
        return super.toString() + "\n" + listOfAns;
    }

    @Override
    public String toStringCorrect(){
        String listOfAns = "";
        int correctIndex = 0;
        String spaceForAnswer = "";

        for(int i = 0; i < this.ANSWER_SPACE / 2; i++){
            spaceForAnswer += "_";
        }

        for(int i = 0; i < this.possibleAnswer.length; i++){
            if (this.possibleAnswer[i].equals(correctAnswer)){
                listOfAns += (i + 1) + ". *** " + this.possibleAnswer[i] + " ***\n";
                correctIndex = i + 1;
            }
            else{
                listOfAns += (i + 1) + ". " + this.possibleAnswer[i] + "\n";
            }
        }
        return spaceForAnswer + correctIndex + spaceForAnswer + " " + this.questionText + " " + this.points + "pts Difficulty: " + this.difficulty + " / " + this.MAX_DIFF + "\n" + listOfAns;
    }
}