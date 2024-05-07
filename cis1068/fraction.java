public class fraction {
    private int numerator, denominator;
    public fraction(int n, int d){
        if(d == 0){
            throw new ArithmeticException("Denominator cannot be 0");
        }
        int gcd = simplify(n, d);
        this.numerator = n / gcd;
        this.denominator = d / gcd;
    }
    private int simplify(int n, int d){
        if(n == d){
            return n;
        }
        if(n > d){
            return simplify(n - d, d);
        }
        else{
            return simplify(d - n, n);
        }     
    }
    public int getNum(){
        return this.numerator;
    }
    public int getDenom(){
        return this.denominator;
    }
    public void setNum(int newN){
        this.numerator = newN;
    }
    public void setDenom(int newD){
        this.denominator = newD;
    }
    public fraction add(fraction A){
        return new fraction(this.numerator * A.denominator + this.denominator * A.numerator, this.denominator * A.denominator);
    }
    public boolean equals(fraction A){
        int gcd1 = simplify(this.numerator, this.denominator);
        int gcd2 = simplify(A.getNum(), A.getDenom());
        return this.numerator / gcd1 == A.getNum() / gcd2 && this.denominator / gcd1 == A.getDenom() / gcd2;
    }
    public String toString(){
        return this.numerator + "/" + this.denominator;
    }
}