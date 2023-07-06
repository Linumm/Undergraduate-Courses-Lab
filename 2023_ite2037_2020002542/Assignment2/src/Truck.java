import java.util.ArrayList;
import java.util.Arrays;

public class Truck {
    private int ID;
    private double fuel;
    private Warehouse currentWarehouse;
    private int current_weight;
    private int max_weight;
    private int max_all_cargoes;
    private int max_basic;
    private int max_heavy;
    private int max_dangerous;
    private int max_liquid;
    private double fuel_per_km;
    private int[] num_of_each_cargo; //0: Basic, 1: Pure-heavy, 2: Dangerous, 3: Liquid

    private ArrayList<Cargo> cargoes;

    //=============================
    public Truck(int ID, Warehouse w, int totalWeight, int maxNumOfAllCargoes, int maxNumofHeavyCargoes, int maxNumofDangerousCargoes,
                 int maxNumofLiquidCargoes, double fuelPerKm)
    {
        this.ID = ID;
        this.currentWarehouse = w;
        currentWarehouse.incomingTruck(this);

        this.current_weight = 0;
        this.max_weight = totalWeight;
        this.max_all_cargoes = maxNumOfAllCargoes;
        this.max_heavy = maxNumofHeavyCargoes;
        this.max_dangerous = maxNumofDangerousCargoes;
        this.max_liquid = maxNumofLiquidCargoes;
        this.fuel_per_km = fuelPerKm;
        this.max_basic = max_all_cargoes-max_heavy;

        this.fuel = 0;
        this.num_of_each_cargo = new int[4];
        this.cargoes = new ArrayList<Cargo>();
    }
    public int getID() { return this.ID; }
    public Warehouse getCurrentWarehouse() { return currentWarehouse; }
    public double getFuel() { return this.fuel; }
    public ArrayList<Cargo> getCargoes() { return this.cargoes; }

    public int currentCargoNum()
    {
        int num = 0;
        for (int i=0; i<4; i++)
            num += this.num_of_each_cargo[i];
        return num;
    }
    boolean canLoad(Cargo cargo)
    {
        String cargo_type = cargo.getClass().getSimpleName();
        int idx_type;

        if (currentCargoNum() == max_all_cargoes)
            return false;
        if (cargo.getWeight() + current_weight >= max_weight)
            return false;

        if (cargo_type.equals("BasicCargo")) {
            idx_type = 0;
            if (num_of_each_cargo[idx_type]+1 > max_basic) {
                System.out.println("Loading is not possible! Already " + max_basic + " basic cargoes");
                return false;
            }
        }
        else if (cargo_type.equals("DangerousCargo")) {
            idx_type = 2;
            if (num_of_each_cargo[idx_type]+1 > max_dangerous) {
                System.out.println("Loading is not possible! Already " + max_dangerous + " dangerous cargoes");
                return false;
            }
            if (num_of_each_cargo[1]+1 > max_heavy) {
                System.out.println("Loading is not possible! Already " + max_heavy + " heavy cargoes");
                return false;
            }
        }
        else if (cargo_type.equals("LiquidCargo")) {
            idx_type = 3;
            if (num_of_each_cargo[idx_type]+1 > max_liquid) {
                System.out.println("Loading is not possible! Already " + max_liquid + " basic liquid cargoes");
                return false;
            }
            if (num_of_each_cargo[1]+1 > max_heavy) {
                System.out.println("Loading is not possible! Already " + max_heavy + " heavy cargoes");
                return false;
            }
        }
        else {
            idx_type = 1;
            if (num_of_each_cargo[idx_type]+1 > max_heavy) {
                System.out.println("Loading is not possible! Already " + max_heavy + " heavy cargoes");
                return false;
            }
        }

        return true;
    }
    public boolean load(Cargo c)
    {
        if (c == null)
            return false;

        if (!canLoad(c))
            return false;

        // Find sorted index to be inserted
        int insert_idx = 0;
        for (int i=0; i<cargoes.size(); i++) {
            if (c.getID() <= cargoes.get(i).getID()) {
                insert_idx = i;
            }
        }
        cargoes.add(insert_idx, c);

        current_weight += c.getWeight();

        if (c.getClass().getSimpleName().equals("BasicCargo"))
            num_of_each_cargo[0]++;
        else if (c.getClass().getSimpleName().equals("DangerousCargo"))
            num_of_each_cargo[2]++;
        else if (c.getClass().getSimpleName().equals("LiquidCargo"))
            num_of_each_cargo[3]++;
        else
            num_of_each_cargo[1]++;

        return true;
    }

    public boolean unload(Cargo c)
    {
        // Pop target-cargo from Cargoes arraylist
        if (c == null)
            return false;

        // Fix truck instances
        current_weight -= c.getWeight();

        if (c.getClass().getSimpleName().equals("BasicCargo"))
            num_of_each_cargo[0]--;
        else if (c.getClass().getSimpleName().equals("DangerousCargo"))
            num_of_each_cargo[2]--;
        else if (c.getClass().getSimpleName().equals("LiquidCargo"))
            num_of_each_cargo[3]--;
        else
            num_of_each_cargo[1]--;

        // Now push to Warehouse
        currentWarehouse.pushCargo(c);

        return true;
    }

    public Cargo popCargo(int id)
    {
        for (int i=0; i<cargoes.size(); i++) {
            if (cargoes.get(i).getID() == id) {
                Cargo tmp = cargoes.get(i);
                cargoes.remove(i);
                return tmp;
            }
        }
        // If not exist
        return null;
    }

    public ArrayList<Cargo> getCurrentCargoes()
    {
        return this.cargoes;
    }

    //----------Method about Fuel
    public boolean sailTo(Warehouse w)
    {
        // Get distance first
        double distance = currentWarehouse.getDistance(w);
        double fuel_consumption = this.fuel_per_km * distance + distance * sumCargoFuelConsumption();

        if (fuel >= fuel_consumption) { // If it has enough
            fuel -= fuel_consumption;
            currentWarehouse.outgoingTruck(this);
            currentWarehouse = w;
            return true;
        }
        return false;
    }

    public void reFuel(double amount)
    {
        fuel += amount;
    }

    public double sumCargoFuelConsumption()
    {
        double sum = 0;
        for (int i=0; i<cargoes.size(); i++) {
            sum += cargoes.get(i).consumption();
        }
        return sum;
    }
}
