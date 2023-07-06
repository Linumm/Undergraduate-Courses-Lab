import java.sql.Array;
import java.util.ArrayList;
import java.util.Collections;

public abstract class Cargo{
    protected int ID;
    protected int weight;
    public Cargo(int ID, int weight)
    {
        this.ID = ID;
        this.weight = weight;
    }
    public int getID()
    {
        return this.ID;
    }
    public int getWeight()
    {
        return this.weight;
    }
    public abstract double consumption();
    public static ArrayList<ArrayList<Cargo>> sortCargoes(ArrayList<Cargo> cargoes)
    {
        // 0: Basic, 1: Pure-heavy, 2: Dangerous, 3: Liquid
        ArrayList<Cargo> basic = new ArrayList<Cargo>();
        ArrayList<Cargo> p_heavy = new ArrayList<Cargo>();
        ArrayList<Cargo> dangerous = new ArrayList<Cargo>();
        ArrayList<Cargo> liquid = new ArrayList<Cargo>();

        ArrayList<ArrayList<Cargo>> target = new ArrayList<ArrayList<Cargo>>();

        Cargo tmp_for_swap;
        // Sort cargoes by it's ID.
        for (int i=0; i<cargoes.size(); i++) {
            Cargo min = cargoes.get(i);
            for (int j=1; j<cargoes.size(); j++) {
                if (min.getID() > cargoes.get(j).getID()) {
                    Collections.swap(cargoes, i, j);
                }
            }
        }

        for (int i=0; i<cargoes.size(); i++) {
            System.out.println(cargoes.get(i).getID());
        }

        for (int i=0; i<cargoes.size(); i++) {
            if (cargoes.get(i).getClass().getSimpleName() == "BasicCargo") {
                basic.add(cargoes.get(i));
            }
            else if (cargoes.get(i).getClass().getSimpleName() == "DangerousCargo") {
                dangerous.add(cargoes.get(i));
            }
            else if (cargoes.get(i).getClass().getSimpleName() == "LiquidCargo") {
                liquid.add(cargoes.get(i));
            }
            else { // Pure-heavy (not dangerous, not liquid)
                p_heavy.add(cargoes.get(i));
            }
        }

        target.add(basic);
        target.add(p_heavy);
        target.add(dangerous);
        target.add(liquid);

        return target;
    }
}
