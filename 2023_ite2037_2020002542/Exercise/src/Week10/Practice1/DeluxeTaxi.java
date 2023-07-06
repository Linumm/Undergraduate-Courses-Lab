package Week10.Practice1;

public class DeluxeTaxi extends Taxi{
    private double fare_per_kilometer;
    private double base_distance;
    private double base_fee;

    public DeluxeTaxi(int car_num, double rate_per_km)
    {
        super(car_num);
        fare_per_kilometer = rate_per_km;
        base_distance = 3;
        base_fee = 5;
    }

    public String toString()
    {
        return super.toString() + " Fare/Km: " + fare_per_kilometer + " Base Distance: " + base_distance + " Base Fee: " + base_fee;
    }

    public double getPaid(double dis)
    {
        if (dis-base_distance >= 0)
            return fare_per_kilometer*(dis-base_distance)+base_fee;
        else
            return base_fee;
    }
}
