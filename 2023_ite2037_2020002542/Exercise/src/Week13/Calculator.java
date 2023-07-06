package Week13;

public class Calculator implements ComplexNumberCalculator, RealNumberCalculator {
    public ComplexNumber add(ComplexNumber c1, ComplexNumber c2)
    {
        ComplexNumber output = new ComplexNumber(add(c1.real, c2.real), add(c1.imaginary, c2.imaginary));
        return output;
    }
    public ComplexNumber sub(ComplexNumber c1, ComplexNumber c2)
    {
        ComplexNumber output = new ComplexNumber(sub(c1.real, c2.real), sub(c1.imaginary, c2.imaginary));
        return output;
    }
    public ComplexNumber mul(ComplexNumber c1, ComplexNumber c2)
    {
        ComplexNumber output = new ComplexNumber(mul(c1.real, c2.real), mul(c1.imaginary, c2.imaginary));
        return output;
    }
    public ComplexNumber.RealNumber add(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2)
    {
        ComplexNumber.RealNumber output = new ComplexNumber.RealNumber(r1.dividend*r2.divisor+r2.dividend*r1.divisor, r1.divisor*r2.divisor);
        return output;
    }
    public ComplexNumber.RealNumber sub(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2)
    {
        ComplexNumber.RealNumber output = new ComplexNumber.RealNumber(r1.dividend*r2.divisor, r2.dividend*r1.divisor);
        return output;
    }
    public ComplexNumber.RealNumber mul(ComplexNumber.RealNumber r1, ComplexNumber.RealNumber r2)
    {
        ComplexNumber.RealNumber output = new ComplexNumber.RealNumber(r1.dividend*r2.dividend, r2.divisor*r1.divisor);
        return output;
    }
    public void printResult(ComplexNumber c)
    {
        System.out.println("Real : "+ c.real.toString() + ", Imaginary: "+ c.imaginary.toString());
    }
}
