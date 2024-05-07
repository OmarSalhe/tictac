import java.time.LocalDateTime;
public class todoListMain {
    public static void main(String[] args){
        final int MAX_TASK = 5;
        LocalDateTime endOfFriday = LocalDateTime.of(2024, 4, 12, 23, 59, 0);      
        task myHomeWork[] = new task[MAX_TASK];
        myHomeWork[0] = new task("this", 1, 12, endOfFriday);
        myHomeWork[1] = new task("Paper 3", 3, 120, endOfFriday);
        myHomeWork[2] = new task("calc3 hw", 2, 90, endOfFriday);
        myHomeWork[3] = new task("Comm Paper", 2, 60, endOfFriday);
        myHomeWork[4] = new task("PeerReview Paper3", 2, 15, endOfFriday); 
        
        task filler = new task("filler", 0, 0, endOfFriday);
        honeyDoList thisWeek = new honeyDoList(MAX_TASK);
        for(int i = 0; i < MAX_TASK; i++){
            thisWeek.addTask(myHomeWork[i]);
        }
        System.out.println(thisWeek);
        System.out.println(thisWeek.find("calc3 hw"));

        thisWeek.getTask(thisWeek.find("Comm Paper")).decreasePriority(1);

        thisWeek.addTask(filler);
        thisWeek.getTask(thisWeek.find("filler")).increasePriority(3);
        thisWeek.getTask(thisWeek.find("filler")).setName("new filler");
        thisWeek.getTask(thisWeek.find("new filler")).setEstMinsToComplete(1);

        System.out.println("Completed: " + thisWeek.completeTask(0).getName());
        System.out.println(thisWeek);

        System.out.println(thisWeek.getTask(thisWeek.shortestTime()).getName() + " should be the quickest, taking only " + thisWeek.getTask(thisWeek.shortestTime()).getEstMinsToComplete() + " minutes" );
        task late[] = thisWeek.overdueTasks();
        
        if(late.length > 0){    
            for (int i = 0; i < late.length; i++){
                System.out.println(late[i].getName() + " is late");
            }
        }
        else{
            System.out.println("No late assignments");
        }
        System.out.println("Total minutes is " + thisWeek.totalTime());
    }
}
