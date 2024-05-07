public class getyouacat {
    final static int MAX_ANIMAL = 6; //only 6 animals listed in the song
    final static String AnimalName[] = {"cat", "hen", "duck", "goose", "sheep", "pig"};
    
    public static void main(String args[]){
        for(int animal = 0; animal < MAX_ANIMAL; animal++){
            lyrics(animal);
            System.out.println(""); //prints a new line
        }
    }

    public static void lyrics(int animal){
        System.out.println("Bought me a "+ AnimalName[animal] + " and the " + AnimalName[animal] + " pleased me,");
        System.out.println("I fed my " + AnimalName[animal] + " under yonder tree.");
        
        if (animal != 0){   //if the animal isnt cat then loop the lyrics until cat is reached
            for (int i = animal; i + 1 > 0; i--){   // i = current song stanza/paragraph
                animal_sounds(i);
            }
        }
        else{   // if currently on cat then print the lyrics as normal
            animal_sounds(animal);
        }
    }

    public static void animal_sounds(int sound){    //different sounds each animal makes with proper punctuation
        switch(sound){
            // 0 = Cat, 1 = Hen, 2 = Duck, 3 = Goose, 4 = Sheep, 5 = Pig
            case 0:
                System.out.println("Cat goes fiddle-i-dee.");
                break;

            case 1:
                System.out.println("Hen goes chimmy-chuck, chimmy-chuck,");
                break;

            case 2:
                System.out.println("Duck goes quack, quack,");
                break;

            case 3:
                System.out.println("Goose goes hissy, hissy,");
                break;

            case 4:
                System.out.println("Sheep goes baa, baa,");
                break;

            case 5:
                System.out.println("Pig goes oink, oink,");
                break;
        }
    }
    
}
