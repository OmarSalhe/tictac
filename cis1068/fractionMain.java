public class fractionMain {
    public static void main(String[] args) {
        fraction fract1 = new fraction(30, 100);
        fraction fract2 = new fraction(5, 2);
        System.out.println(fract1);
        System.out.println(fract2);
        System.out.println(fract1.getNum());
        System.out.println(fract2.getDenom());
        System.out.println(fract1 + " + " + fract2 + " = " + fract1.add(fract2));
        
        if(fract1.equals(fract2)){
            System.out.println("They're equal!");
        }
        else{
            System.out.println("Not equal!");
        }
        fract2.setNum(6);
        fract1.setDenom(1);
        if(fract1.equals(fract2)){
            System.out.println("They're equal!");
        }
        else{
            System.out.println("Not equal!");
        }
    }
}
