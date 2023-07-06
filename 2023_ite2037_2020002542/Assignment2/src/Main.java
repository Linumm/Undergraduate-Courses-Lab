import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        // Generate a new Scanner object to access data from the input file in the directory indicated by "args[0]".
        Scanner in = new Scanner(new File(args[0]));
        PrintStream out = new PrintStream(new File(args[1]));

        // Your Implementation
        int num_of_events = in.nextInt();
        //in.nextLine();
        int event_type;
        int cargo_count = 0;
        int truck_count = 0;
        int warehouse_id;
        int cargo_weight;
        int cargo_id;
        int truck_id;


        ArrayList<Warehouse> warehouse_list = new ArrayList<Warehouse>();
        ArrayList<Truck> truck_list = new ArrayList<Truck>();

        for (int i=0; i<num_of_events; i++) {
            event_type = in.nextInt();

            switch (event_type) {
                case 1:
                    warehouse_id = in.nextInt();
                    cargo_weight = in.nextInt();
                    String special_type;

                    Warehouse place = getWarehouse(warehouse_list, warehouse_id);
                    if (!in.hasNextInt()) {
                        special_type = in.next();

                        if (special_type.equals("D")) {
                            DangerousCargo new_cargo = new DangerousCargo(cargo_count, cargo_weight);
                            place.pushCargo(new_cargo);
                        }
                        else if (special_type.equals("L")) {
                            LiquidCargo new_cargo = new LiquidCargo(cargo_count, cargo_weight);
                            place.pushCargo(new_cargo);
                        }
                    }
                    else {
                        if (cargo_weight <= 1000) {
                            BasicCargo new_cargo = new BasicCargo(cargo_count, cargo_weight);
                            place.pushCargo(new_cargo);
                        } else {
                            HeavyCargo new_cargo = new HeavyCargo(cargo_count, cargo_weight);
                            place.pushCargo(new_cargo);
                        }
                    }
                    cargo_count++;
                    break;
                case 2:
                    warehouse_id = in.nextInt();
                    int max_cargo_weight = in.nextInt();
                    int max_cargo_hold = in.nextInt();
                    int max_heavy = in.nextInt();
                    int max_dangerous = in.nextInt();
                    int max_liquid = in.nextInt();
                    double fuel_per_km = in.nextDouble();

                    Truck new_truck = new Truck(truck_count, getWarehouse(warehouse_list, warehouse_id), max_cargo_weight, max_cargo_hold, max_heavy, max_dangerous,
                    max_liquid, fuel_per_km);
                    // Truck constructor에서 바로 warehouse로 push
                    truck_list.add(new_truck);
                    truck_count++;
                    break;
                case 3:
                    double x = in.nextDouble();
                    double y = in.nextDouble();
                    Warehouse new_warehouse = new Warehouse(warehouse_list.size(), x, y);
                    warehouse_list.add(new_warehouse);
                    break;
                case 4:
                    truck_id = in.nextInt();
                    cargo_id = in.nextInt();
                    Truck tmp = getTruck(truck_list, truck_id);
                    if (tmp.load(tmp.getCurrentWarehouse().getCargo(cargo_id)))
                        tmp.getCurrentWarehouse().popCargo(cargo_id);
                    break;
                case 5:
                    truck_id = in.nextInt();
                    cargo_id = in.nextInt();
                    tmp = getTruck(truck_list, truck_id);
                    Cargo target_cargo = tmp.getCurrentWarehouse().getCargo(cargo_id);
                    if (tmp.unload(target_cargo))
                        tmp.getCurrentWarehouse().pushCargo(target_cargo);
                    break;
                case 6:
                    truck_id = in.nextInt();
                    warehouse_id = in.nextInt();
                    tmp = getTruck(truck_list, truck_id);
                    Warehouse target_warehouse = getWarehouse(warehouse_list, warehouse_id);
                    if (tmp.sailTo(target_warehouse)) {
                        target_warehouse.incomingTruck(tmp);
                    }
                    System.out.println("6 " + truck_id + " " + warehouse_id);
                    break;
                case 7:
                    truck_id = in.nextInt();
                    double fuel_amount = in.nextDouble();
                    tmp = getTruck(truck_list, truck_id);
                    if (tmp!= null)
                        tmp.reFuel(fuel_amount);
                    break;
            }
        }
        // Close the Scanner object.
        in.close();

        for (int i=0; i<warehouse_list.size(); i++) {
            // Print out Warehouse id and coordinate]
            Warehouse wh = warehouse_list.get(i);
            out.print("Warehouse " + wh.getID() + ": (");
            out.println(String.format("%.1f, %.1f", wh.getX(), wh.getY()) + ")");
            // Print out Cargo info
            ArrayList<ArrayList<Cargo>> sorted = Cargo.sortCargoes(wh.getCargoes());
            for (int j = 0; j < 4; j++) {
                if (sorted.get(j).size() != 0) {
                    out.print("  " + sorted.get(j).getClass().getSimpleName() + ": ");
                    for (int k = 0; k < sorted.get(j).size(); k++) {
                        out.print(sorted.get(j).get(k).getID() + " ");
                    }
                    out.println();
                }
            }
            // Print out current Truck info
            for (int j = 0; j < wh.getCurrent().size(); j++) {
                Truck truck_in_wh = wh.getCurrent().get(j);
                out.print(String.format("  Truck %d", truck_in_wh.getID()));
                out.println(String.format(": %.1f", truck_in_wh.getFuel()));

                ArrayList<ArrayList<Cargo>> truck_cargoes = Cargo.sortCargoes(truck_in_wh.getCargoes());

                for (int p=0; p<4; p++) {
                    if (truck_cargoes.get(p).size() == 0)
                        continue;
                    out.print("   " + truck_cargoes.get(p).get(0).getClass().getSimpleName() + ": ");
                    for (int k=0; k<truck_cargoes.get(p).size(); k++) {
                        out.print(truck_cargoes.get(p).get(k).getID() + " ");
                    }
                    out.println();
                }

            }
        }

        // Print the string to the output file.

        // Close the PrintStream object.
        out.close();
    }

    public static Warehouse getWarehouse(ArrayList<Warehouse> warehouse_list, int id)
    {
        for (int i=0; i<warehouse_list.size(); i++) {
            if (warehouse_list.get(i).getID() == id)
                return warehouse_list.get(i);
        }
        return null;
    }

    public static Truck getTruck(ArrayList<Truck> truck_list, int id)
    {
        for (int i=0; i<truck_list.size(); i++) {
            if (truck_list.get(i).getID() == id)
                return truck_list.get(i);
        }
        return null;
    }

}
