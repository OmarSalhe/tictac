public class carMain {
    public static void main(String[] args) {
        car car[] = new car[3];
        String carNames[] = {"SpeedRacer", "Hyundai", "Toyota"};
        String carModel[] = {"Mach 5", "Elantra", "Camry"};
        int year[] = {1967, 2017, 2004};
        int mpg[] = {1000, 18, 12};
        int miles[] = {1000000, 120042, 18000};
        int maxFuel[] = {20, 17, 19};
        int fuelLeft[] = {800, 14, 8};
        
        for(int i = 0; i < 3; i++){
            car[i] = new car(carNames[i], carModel[i], year[i], mpg[i], miles[i], maxFuel[i], fuelLeft[i]);
            System.out.println(car[i]);
            car[i].drive(18);
            car[i].fillTank(i);
            System.out.println(car[i].getFuelRemaing());
        }
    }
}
