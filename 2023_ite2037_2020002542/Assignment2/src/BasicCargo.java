public class BasicCargo extends Cargo{
    protected double fuel_consumption;
    public BasicCargo(int ID, int weight)
    {
        super(ID, weight);
        this.fuel_consumption = 1.5 * weight;
    }

    @Override
    public double consumption() {
        return fuel_consumption;
    }
}
