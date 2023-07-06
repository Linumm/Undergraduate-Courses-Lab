public class LiquidCargo extends HeavyCargo{
    public LiquidCargo(int ID, int weight)
    {
        super(ID, weight);
        this.fuel_consumption = 3.5 * weight;
    }
}
