package Week13;

public class ComplexNumber {
    protected RealNumber real;
    protected RealNumber imaginary;
    public static class RealNumber {
        protected int dividend;
        protected int divisor;
        public RealNumber(int n1, int n2)
        {
            this.dividend = n1;
            this.divisor = n2;
        }
        public String toString()
        {
            return (dividend + "/" + divisor);
        }

    }
    public ComplexNumber(RealNumber real, RealNumber imaginary)
    {
        this.real = new RealNumber(real.dividend, real.divisor);
        this.imaginary = new RealNumber(imaginary.dividend, imaginary.divisor);
    }
}
