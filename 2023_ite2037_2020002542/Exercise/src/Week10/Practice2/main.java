package Week10.Practice2;
import java.util.Random;
import java.util.Scanner;


public class main {
    public static void main(String[] Args)
    {
        Organism[][] world = new Organism[10][10];
        boolean[][] used_coordinate = new boolean[10][10];
        Ant[] ant_units = new Ant[200];
        Doodlebug[] doodle_units = new Doodlebug[50];
        // ~_count don't care whether the ant is already dead
        int ant_count = 0;
        int doodle_count = 0;

        Random rnd = new Random();
        Scanner scn = new Scanner(System.in);

        int row;
        int col;
        for (int i=0; i<2; i++) { // Make 2 Doodlebugs
            while (true) {
                row = rnd.nextInt(10);
                col = rnd.nextInt(10);
                if (used_coordinate[row][col])
                    continue;
                else {
                    used_coordinate[row][col] = true;
                    Doodlebug doodle= new Doodlebug(row, col);
                    world[row][col] = doodle;
                    doodle_units[doodle_count++] = doodle;
                    break;
                }
            }
        }

        for (int i=0; i<20; i++) { // Make 20 Ants
            while (true) {
                row = rnd.nextInt(10);
                col = rnd.nextInt(10);
                if (used_coordinate[row][col])
                    continue;
                else {
                    used_coordinate[row][col] = true;
                    Ant ant = new Ant(row, col);
                    world[row][col] = ant;
                    ant_units[ant_count++] = ant;
                    break;
                }
            }
        }

        while (true) {
            System.out.println("==");
            String command = scn.nextLine();
            if (command.length() != 0)
                System.exit(1);

            // Control all units by each unit's array
            for (int i=0; i<doodle_count; i++) {
                if (doodle_units[i] != null)
                    doodle_units[i].Action(world);
            }

            for (int i=0; i<ant_count; i++) {
                if (ant_units[i] != null)
                    ant_units[i].Action(world);
            }

            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    if (world[i][j] == null)
                        System.out.print("_ ");
                    else if (world[i][j].getClass().getSimpleName().equals("Ant"))
                        System.out.print("o ");
                    else if (world[i][j].getClass().getSimpleName().equals("Doodlebug"))
                        System.out.print("X ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
