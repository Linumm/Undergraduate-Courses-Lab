package Week10.Practice2;
import java.util.Random;

public class Ant extends Organism{
    public Ant(int row, int col)
    {
        super(row, col);
    }

    public void Action(Organism[][] grid)
    {
        // If they're not in grid, it means they are removed though they are still in units data
        if (grid[row][col] == null || !grid[row][col].getClass().getSimpleName().equals("Ant"))
            return;
        Move(grid);
        if (turn_passed >= 3)
            Breed(grid);
        turn_passed++;
    }
    public void Move(Organism[][] grid)
    {
        Random rnd = new Random();
        //Direction = {{U:0}, {R:1}, {D:2}, {L:3}}
        int direction = rnd.nextInt(4);
        int new_row = this.row;
        int new_col = this.col;
        switch (direction) {
            case 0: // Up
                new_row--;
                break;
            case 1: // Right
                new_col++;
                break;
            case 2: // Down
                new_row++;
                break;
            case 3: // Left
                new_col--;
                break;
        }

        if (availableCell(grid, new_row, new_col)) {
            if (grid[new_row][new_col] == null) {
                grid[new_row][new_col] = this;
                grid[this.row][this.col] = null;
                // set new row and col
                this.row = new_row;
                this.col = new_col;
            }
        }
    }

    public void Breed(Organism[][] grid)
    {
        Random rnd = new Random();
        int new_row = this.row;
        int new_col = this.col;
        boolean[] checked = {false, false, false, false};
        while (true) {
            int direction = rnd.nextInt(4);
            if (checked[0] && checked[1] && checked[2] && checked[3])
                return; // In case that all sides are impossible, just return and delay breeding
            if (checked[direction])
                continue; // Skip the side already checked
            switch (direction) {
                case 0: // Up
                    new_row--;
                    break;
                case 1: // Right
                    new_col++;
                    break;
                case 2: // Down
                    new_row++;
                    break;
                case 3: // Left
                    new_col--;
                    break;
            }
            checked[direction] = true;
            if (availableCell(grid, new_row, new_col))
                break;
        }
        Ant offspring = new Ant(new_row, new_col);
        grid[new_row][new_col] = offspring;
        turn_passed = 0; // Reset turn passed
    }
}
