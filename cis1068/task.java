import java.time.LocalDateTime;

public class task {
    private String name;
    private int priority;
    private int estMinsToComplete;
    private LocalDateTime whenDue;

    public task(String name, int priority, int estMinsToComplete, LocalDateTime whenDue){
        this.name = name;
        this.priority = priority;
        this.estMinsToComplete = estMinsToComplete;
        this.whenDue = whenDue;
    }
    public String toString() {
        return "The task: " + this.name + " is priority " + this.priority + " and will take about " + this.estMinsToComplete + " minutes to complete";
    }
    public int getPriority() {
        return priority;
    }
    public String getName() {
        return name;
    }
    public int getEstMinsToComplete() {
        return estMinsToComplete;
    }
    public LocalDateTime getWhenDue() {
        return whenDue;
    }
    public void setName(String newName) {
        this.name = newName;
    }
    public void increasePriority(int amount) {
        if (amount > 0){
            this.priority += amount;
        }
    }
    public void decreasePriority(int amount) {
        if (amount > 0 && amount <= this.priority){
            this.priority -= amount;
        }
    }
    public void setEstMinsToComplete(int estMinsToComplete) {
        this.estMinsToComplete = estMinsToComplete;
    }
    public void setWhenDue(LocalDateTime newDue) {
        this.whenDue = newDue;
    }
    public boolean isOverdue(){
        return LocalDateTime.now().isAfter(this.whenDue);
    }
}
