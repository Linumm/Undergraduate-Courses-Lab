public class DangerousCargo extends HeavyCargo{
    public DangerousCargo(int ID, int weight)
    {
        super(ID, weight);
        this.fuel_consumption = 4.0 * weight;
    }
}
