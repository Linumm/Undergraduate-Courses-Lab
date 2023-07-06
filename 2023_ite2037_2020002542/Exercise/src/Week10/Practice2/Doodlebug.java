package Week10.Practice2;
import java.util.Random;

public class Doodlebug extends Organism{
    private int starved_time;
    public Doodlebug(int row, int col)
    {
        super(row, col);
        this.starved_time = 0;
    }

    public void Action(Organism[][] grid)
    {
        // If they're not in cell, it means they are removed though they are still in units data
        if (grid[row][col] == null || !grid[row][col].getClass().getSimpleName().equals("Doodlebug"))
            return;
        // Find food first
        boolean tmp = findAndEatAnt(grid);
        if (!tmp) {
            Move(grid);
            if (turn_passed >= 8)
                Breed(grid);
            if (starved_time >= 3)
                grid[row][col] = null; // Died by starvation
        }
        else {
            turn_passed++;
            if (turn_passed >= 8)
                Breed(grid);
        }
    }

    public void Move(Organism[][] grid) {
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
                return;
            if (checked[direction])
                continue;
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
        Doodlebug offspring = new Doodlebug(new_row, new_col);
        grid[new_row][new_col] = offspring;
        turn_passed = 0; // Reset turn_passed
    }
    public boolean findAndEatAnt(Organism[][] grid)
    {
        if (availableCell(grid, row+1, col) && grid[row+1][col] != null) {
            if (grid[row+1][col].getClass().getSimpleName().equals("Ant")) {
                grid[row+1][col] = this; // make the cell point this object
                grid[row][col] = null;
                starved_time = 0; // Reset the starved time
                row++;
                return true;
            }
        }
        else if (availableCell(grid, row-1, col) && grid[row-1][col] != null) {
            if (grid[row-1][col].getClass().getSimpleName().equals("Ant")) {
                grid[row-1][col] = this;
                grid[row][col] = null;
                starved_time = 0;
                row--;
                return true;
            }
        }
        else if (availableCell(grid, row, col+1) && grid[row][col+1] != null) {
            if (grid[row][col+1].getClass().getSimpleName().equals("Ant")) {
                grid[row][col+1] = this;
                grid[row][col] = null;
                starved_time = 0;
                col++;
                return true;
            }
        }
        else if (availableCell(grid, row, col-1) && grid[row][col-1] != null) {
            if (grid[row][col-1].getClass().getSimpleName().equals("Ant")) {
                grid[row][col-1] = this;
                grid[row][col] = null;
                starved_time = 0;
                col--;
                return true;
            }
        }
        starved_time++;
        return false;
    }
}
