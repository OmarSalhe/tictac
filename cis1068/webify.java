import java.util.*;
import java.io.*;

//Omar Salhe March 

public class webify {

    public static Map<String, Integer>symbolCount = new HashMap<>();  //keeps track of symbols in use
    public static void main(String[] args) throws FileNotFoundException{
        symbolCount.put("#", 0);
        symbolCount.put("/", 0);

        String fileName;
        fileName = userInput("Enter a file name");
        makeOutput(makeInput(fileName), fileName);
    }

    public static File makeInput(String fileName) throws FileNotFoundException{
        File inputFile = new File(fileName + ".txt");
        addInput(inputFile);
        return inputFile;
    }

    public static void addInput(File inputFile) throws FileNotFoundException{
        PrintStream inputLine = new PrintStream(inputFile);
        while(true){
            String line = userInput("Input a line or 'quit' to quit");
            if("quit".equals(line)){
                break;
            }
            inputLine.println(line);
        }
        inputLine.close();
    }

    public static void makeOutput(File inputFile, String fileName) throws FileNotFoundException{
        File outputFile = new File(fileName + ".html");
        addOutput(inputFile, outputFile);
    }
    public static void addOutput(File inputFile, File outputFile) throws FileNotFoundException{
        Scanner inputLine = new Scanner(inputFile);
        PrintStream outputLine = new PrintStream(outputFile);
        String line, hyperlink = "";
        boolean insideList = false;
        
        outputLine.println("<html>\n<body>");
        while(inputLine.hasNextLine()){
            line = inputLine.nextLine();
            if(line.contains("[")){
                hyperlink = formHyperlink(line.substring(1, line.length() - 1));
                continue;
            }
            else if(line.contains("-")){
                if(!(insideList)){
                    outputLine.println("<ul>");
                    insideList = true;
                }
                outputLine.print(middleman(line.replace("-", "<li>")) + "</li>");
            }
            else{
                if(insideList){
                    outputLine.println("</ul>");
                    insideList = false;
                }
                outputLine.print(middleman(line));
            }
            
            if(line.isEmpty()){
                outputLine.print("<P>");
            }
            else if(!(hasSymbol(line))){
                outputLine.print("<br />");
            }
            outputLine.println();
        }
        outputLine.println(hyperlink);
        outputLine.println("</body>\n</html>");
        inputLine.close();
        outputLine.close();
    }

    public static String formHyperlink(String line){
        String x = "", y = "";

        int startIndex = line.indexOf("[");
        int endIndex = line.indexOf("]", startIndex);

        if (startIndex != -1 && endIndex != -1) {
            x = line.substring(startIndex + 1, endIndex); // Exclude '[' but include ']'
    
            startIndex = line.indexOf("[", endIndex);
            endIndex = line.indexOf("]", startIndex);
    
            if (startIndex != -1 && endIndex != -1) {
                y = line.substring(startIndex + 1, endIndex); // Exclude '[' but include ']'
            }
        }
        return "<a href= \"" + x + "\">"+ y + "</a>";  
    }

    public static boolean hasSymbol(String line){
        for(int i = 0; i < line.length(); i++){
            if((isSymbol(line.charAt(i)))){
                return true;
            }
        }
        return false;
    }
    
    public static boolean isSymbol(char c){
        char translateSymbol[] = {'#', '-', '/'};
        for(char s: translateSymbol){
            if(c == s){
                return true;
            }
        }
        return false;
    }

    public static String middleman(String line){
        String translatedLine = "";
        for(int i = 0; i < line.length(); i++){
            translatedLine += translatedInput(Character.toString(line.charAt(i)));
        }
        return translatedLine;
    }

    public static String translatedInput(String symbol) {
        for(String s: symbolCount.keySet()){
            if(s.equals(symbol)){
                symbolCount.put(symbol, symbolCount.get(symbol) + 1);
                return txtToHTML(symbol, symbolCount.get(symbol));
            }
        }
        return txtToHTML(symbol, 0);
    }

    public static String txtToHTML(String symbol, int count){
        Map<String, String>translate = new HashMap<>(); //translation to html
        translate.put("#", "<h1>");
        translate.put("/", "<em>");   //EC

        for(String s: translate.keySet()){
            if(s.equals(symbol)){
                String openingElement = translate.get(symbol);
                String closingElement = openingElement.replace("<", "</");
                return (count % 2 == 0)? closingElement: openingElement; //if on an even symbol its a closing element, but starting from 0 so its odd instead
            } 
        }
        return symbol;
    }

    public static String userInput(String prompt){  //reduces the number of scanners needed to be made 
        Scanner input = new Scanner(System.in);
        System.out.println(prompt);
        input.close(); //delete for code to work
        return input.nextLine();
    }
}