//Omar Salhe 
// Simple program to calculate semester grade for courses with only Homework and two Exams to be graded/
import java.util.Scanner;
public class grades {
    public static void main(String[] args){
        final int MAX_GRADE = 100;
        double HOMEWORK_WEIGHT, EXAM1_WEIGHT, EXAM2_WEIGHT;

        System.out.print("Homework weight: ");
        HOMEWORK_WEIGHT = getDouble();

        System.out.print("Exam 1 weight: ");
        EXAM1_WEIGHT = getDouble();

        EXAM2_WEIGHT = MAX_GRADE - (HOMEWORK_WEIGHT + EXAM1_WEIGHT); 

        System.out.println("Exam 2 weight: " + EXAM2_WEIGHT);

        //inputs weighted grades to be calculated and processed simulataneously
        System.out.printf("\nCourse Grade: %.2f",total_weighted_grade(HOMEWORK_WEIGHT * hw_section(), EXAM1_WEIGHT * exam1_section(), EXAM2_WEIGHT * exam2_section()));
    
    }

    public static double hw_section(){
        final int LAB_PT = 4, HW_PT = 10, BONUS_PT = 5;
        double avg, num_hw, lab, late, result;

        System.out.println("\nHomework Section \n");

        System.out.print("Number of assignments: ");
        num_hw = getDouble();
        if (num_hw <= 0){ //handles inputs negative and 0 inputs as full scores
            System.out.println("Invalid input. Full score given.");
            return find_homework_grade(LAB_PT, HW_PT, 0, 1, 1, 1);
        }
        else{ // other inputs processed normally
            System.out.print("Average homework result: ");
            avg = getDouble();
    
            System.out.print("Number of late days used: ");
            late = getDouble();
    
            System.out.print("Labs attended: ");
            lab = getDouble();
    
            if (avg < 0){ //ensures no negative inputs for the average
                System.out.println(avg + " is an invalid average. Average set to 0");
                avg = 0;
            }
    
            if (late > 0){
                if ((num_hw / 2) < late){   //acounts for more late days than half the number of assignments
                    result = find_homework_grade(LAB_PT, HW_PT - 1, 0, avg, num_hw, lab); // 10% of 10 is 1
                }
                else{  //if late days are used no bonus points given          
                    result = find_homework_grade(LAB_PT, HW_PT, 0, avg, num_hw, lab); 
                }
            }
            else{ //if not late days 5 bonus points are given
                result = find_homework_grade(LAB_PT, HW_PT, BONUS_PT, avg, num_hw, lab);
            }
            return result; // results = unweighted homework grade
        }
    }

    public static double find_homework_grade(int LAB_PT, int HW_PT, int BONUS_PT, double avg, double num_hw, double lab){
        double earned_pt = avg * HW_PT + (lab * LAB_PT) + BONUS_PT; //points earned by the student
        double total_pt =  num_hw * HW_PT + (LAB_PT * num_hw); // highest amount of points to be recieved, not including bonus points
        System.out.println("Earned Points: " + earned_pt + " / " + total_pt);
        return earned_pt / total_pt;
    }

    //returns the score of exam 1
    public static double exam1_section(){
        double exam1_score, curve;
        final int MAX_GRADE = 100;

        System.out.println("\nExam 1 Section \n");

        System.out.print("Exam 1 Score: ");
        exam1_score = getDouble();

        System.out.print("Exam 1 Curve: ");
        curve = getDouble();

        if ((exam1_score + curve) < curve){ // accounts for negative exam grades
            System.out.println("\n Invalid Exam Score. Exam 1 Score set to 0 \n");
            exam1_score = curve; // 0 + curve = curve
        }
        else{
            exam1_score += curve;
            if (exam1_score > MAX_GRADE){ //ensures grade does not exceed 100
                System.out.println("Exceeded score limit of 100. Score capped at 100");
                exam1_score = MAX_GRADE;
            }
        }
        System.out.println("Exam 1 Score: " + exam1_score + " / " + MAX_GRADE);
        return exam1_score / MAX_GRADE;
    }

    //returns score of exam 2
    public static double exam2_section(){
        final int MAX_GRADE = 100;
        double exam2_score, curve;
    
        System.out.println("\nExam 2 Section \n");
    
        System.out.print("Exam 2 Score: ");
        exam2_score = getDouble();
    
        System.out.print("Exam 2 Curve: ");
        curve = getDouble();

        if ((exam2_score + curve) < curve){ //ensures no negative exam scores
            System.out.println("Invalid Exam Score. Exam 2 Score set to 0");
            exam2_score += curve; // 0 + curve = curve
        }
        else{
            exam2_score += curve;
            if (exam2_score > MAX_GRADE){ // ensures grade does not exceed 100
                System.out.println("Exceeded score limit of 100. Score capped at 100");
                exam2_score = MAX_GRADE;
            }
        }
        System.out.println("Exam 2 Score:" + exam2_score + " / " + MAX_GRADE);
        return exam2_score / MAX_GRADE;
    }

    //calculates students total grade
    public static double total_weighted_grade(double weighted_homework_grade, double weighted_exam1_grade, double weighted_exam2_grade){
        System.out.printf("\nWeighted Homework Grade: %.2f \n", weighted_homework_grade);
        System.out.printf("Weighted Exam 1 Grade: %.2f \n",weighted_exam1_grade);
        System.out.printf("Weighted Exam 2 Grade: %.2f \n", weighted_exam2_grade);

        return weighted_homework_grade + weighted_exam1_grade + weighted_exam2_grade; 
    }

    //method for taking input
    public static double getDouble(){
        Scanner input = new Scanner(System.in); //creates a scanner for user input

        double number = input.nextDouble(); //initially scans for type double
        String trash = input.nextLine(); //removes any remaining newline characters in the stream
        System.out.println(trash);
        input.close();

        return number;
    }
}
