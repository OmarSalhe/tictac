public class car {
    private String make, model;
    private int year, fuelCapacity;
    private double milesDriven, mpg, fuelRemaining;

    public car(String make, String model, int year, double mpg, double milesDriven, int fuelCapacity, double fuelRemaining){
        this.make = make;
        this.model = model;
        this.year = year;
        this.mpg = mpg;
        this.milesDriven = milesDriven;
        this.fuelCapacity = fuelCapacity;
        this.fuelRemaining = fuelRemaining;
    }
    public String toString(){
        return make + " " + model + " " + year + " " + mpg + " " + milesDriven + " " + fuelCapacity + " " + fuelRemaining;
    }
    public void fillTank(double g){
        this.fuelRemaining += g;
    }
    public double getFuelRemaing(){
        return this.fuelRemaining;
    }
    public void drive(double m){
        this.milesDriven += m;
        this.fuelRemaining -= m / mpg;
    }
}