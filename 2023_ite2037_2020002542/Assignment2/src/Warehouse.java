import java.sql.Array;
import java.util.ArrayList;
import java.util.Iterator;
import java.lang.Math;
public class Warehouse {
    private int ID;
    private double X; // coordinate x
    private double Y; // coordinate y
    private ArrayList<Cargo> cargoes;
    private ArrayList<Truck> history;
    private ArrayList<Truck> current;
    //==================================

    public Warehouse(int ID, double x, double y)
    {
        this.ID = ID;
        this.X = x;
        this.Y = y;

        this.cargoes = new ArrayList<Cargo>();
        this.history = new ArrayList<Truck>();
        this.current = new ArrayList<Truck>();
    }
    public int getID() { return this.ID; }
    public double getX() { return this.X; }
    public double getY() { return this.Y; }

    public ArrayList<Cargo> getCargoes() { return this.cargoes; }
    public ArrayList<Truck> getCurrent() { return this.current; }
    public ArrayList<Truck> getHistory() { return this.history; }
    public double getDistance(Warehouse other)
    {
        double other_x = other.getX();
        double other_y = other.getY();
        double distance_pow = Math.pow(this.X-other_x, 2) + Math.pow(this.Y-other_y, 2);
        return Math.sqrt(distance_pow);
    }
    public void incomingTruck(Truck t)
    {
        // Add "t" to current
        current.add(t);
    }
    public void outgoingTruck(Truck t)
    {
        current.remove(current.indexOf((t)));
        history.add(t);
    }
    public void pushCargo(Cargo cargo)
    {
        cargoes.add(cargo);
    }

    public void popCargo(int id)
    {
        for (int i=0; i<cargoes.size(); i++) {
            if (cargoes.get(i).getID() == id) {
                cargoes.remove(i);
            }
        }
    }

    public Cargo getCargo(int id)
    {
        for (int i=0; i<cargoes.size(); i++) {
            if (cargoes.get(i).getID() == id) {
                return cargoes.get(i);
            }
        }
        // If not exist
        return null;
    }
}
