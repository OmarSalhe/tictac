import java.io.FileNotFoundException;

public class questionTest {
    public static void main(String[] args) throws FileNotFoundException {
        int pts = 10, diff = 5;
        String choices[] = {"Peter Griffin", "Scooby Doo", "Spongebob Squarepants", "Eric Cartman"};
        String q1 = "Who lives in a pineapple under the sea?";

        objectiveQuestion x1 = new multipleChoiceQuestion(pts, diff, q1, choices, choices[2]);
        System.out.println(x1);
        System.out.println(x1.toStringCorrect());

        objectiveQuestion x2 = new objectiveQuestion(pts - 1, diff - 1, "5 - 1 = ?", "4");
        System.out.println(x2);
        System.out.println(x2.toStringCorrect());

        String q2 = "he was just 14, When his parents built a very strange machine", ans = "Danny Phantom";

        objectiveQuestion x3 = new fillInTheBlankQuestion(pts - 2, diff - 3, q2, ans);
        System.out.println(x3);
        System.out.println(x3.toStringCorrect());

        test x4 = new test();
        x4.addQuestion(x1);
        x4.addQuestion(x2);
        x4.addQuestion(x3);

        System.out.println(x4);
        x4.testToFile("finals");
    }
}
