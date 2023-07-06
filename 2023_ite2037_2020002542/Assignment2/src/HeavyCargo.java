public class HeavyCargo extends Cargo{
    protected double fuel_consumption;
    public HeavyCargo(int ID, int weight)
    {
        super(ID, weight);
        this.fuel_consumption = 2.5 * weight;
    }

    @Override
    public double consumption() {
        return fuel_consumption;
    }
}
