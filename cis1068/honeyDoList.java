import java.util.Arrays;

public class honeyDoList {
    private int INITIAL_CAPACITY;
    private task tasks[];
    private int numTasks;
    private int totalTime;

    public honeyDoList(int INITIAL_CAPACITY){
        this.INITIAL_CAPACITY = INITIAL_CAPACITY;
        this.tasks = new task[INITIAL_CAPACITY];
        this.numTasks = 0;
        this.totalTime = 0;
    }
    public String toString() {
        String list = "";
        for(int i = 0; i < this.numTasks; i++){
            list += tasks[i].toString() + "\n";
        }
        return list;
    }
    public int find(String name){
        int index = 0;
        for(task i: tasks){
            if(i.getName().equals(name)){
                return index;
            }
            index++;
        }
        return -1;
    }
    public void addTask(task newTask){
        if(this.numTasks < INITIAL_CAPACITY){
            this.tasks[this.numTasks] = newTask;
            this.numTasks++;
            return;
        }
        this.tasks = Arrays.copyOf(tasks, numTasks + 1);
        this.tasks[numTasks] = newTask;
        this.numTasks++;
    }
    public int totalTime(){
        this.totalTime = 0;
        for(int i = 0; i < this.numTasks; i++){
            this.totalTime += this.tasks[i].getEstMinsToComplete();
        }
        return this.totalTime;
    }
    public int shortestTime(){
        int least = 100000000, index = -1;
        for(int i = 0; i < this.numTasks; i++){
            if(this.tasks[i].getEstMinsToComplete() < least){
                least = this.tasks[i].getEstMinsToComplete();
                index = i;
            }
        }
        return index;
    }
    public task completeTask(int index){
        if(index < 0 || index >= numTasks){
            return null;
        }
        task finishedTask = this.tasks[index];
        for(int i = index; i < this.numTasks - 1; i++){
            this.tasks[i] = this.tasks[i + 1]; //replaces initial task with the next task
        }
        this.numTasks--;
        this.totalTime -= finishedTask.getEstMinsToComplete();
        return finishedTask;
    }
    public task getTask(int index){
        if(index < 0 || index >= numTasks){
            return null;
        }
        return this.tasks[index];
    }
    public task[] overdueTasks(){
        task tmp[] = new task[this.numTasks];
        int overdueTask = 0;
        for(int i = 0; i < this.numTasks; i++){
            if(this.tasks[i].isOverdue()){
                tmp[overdueTask] = this.tasks[i];
                overdueTask++;
            }
        }
        return Arrays.copyOf(tmp, overdueTask);
    }
}
