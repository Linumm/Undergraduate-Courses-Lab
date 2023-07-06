package Week10.Practice1;

public abstract class Taxi {
    protected int car_num;
    protected double distance;
    protected double income;

    public Taxi(int car_num)
    {
        this.car_num = car_num;
        this.distance = 0;
        this.income = 0;
    }

    public String toString()
    {
        return "Car Num: " + car_num + " Distance: " + distance + " Income: " + income;
    }

    public abstract double getPaid(double distance);

    public void doDrive(double dis)
    {
        this.income += getPaid(dis);
        this.distance += dis;
    }

    public boolean earnMore(Taxi t)
    {
        return this.income >= t.income;
    }
}
