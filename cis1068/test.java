import java.util.*;
import java.io.*;

public class test {
    private List<objectiveQuestion> listOfQuestions;
    private int totalPoints;
 
    public test(){
        this.listOfQuestions = new ArrayList<>();
        this.totalPoints = 0;
    }

    public void addQuestion(objectiveQuestion newQuestion){
        listOfQuestions.add(newQuestion);
        this.totalPoints += newQuestion.getPoints();
    }

    public String toString(){
        String testSheet = "";
        for(int i = 0; i < this.listOfQuestions.size(); i++){
            testSheet += this.listOfQuestions.get(i) + "\n";
        }
        return testSheet;
    }

    public String printAnswer(){
        String answerSheet = "";
        for(int i = 0; i < this.listOfQuestions.size(); i++){
            answerSheet += this.listOfQuestions.get(i).toStringCorrect() + "\n";
        }
        return answerSheet;
    }

    public void testToFile(String filename) throws FileNotFoundException{
        PrintStream out = new PrintStream(new File(filename + ".txt"));
        out.println("Total Points: " + this.totalPoints + "\n");
        out.println("-----------Questions-----------");
        out.println(this);

        out.println("-----------Answers-----------");
        out.println(this.printAnswer());
        out.close();
    }
}
