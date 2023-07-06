package Week10.Practice2;

import java.util.Random;

public abstract class Organism {
    protected int turn_passed;
    protected int row;
    protected int col;

    public Organism(int row, int col)
    {
        this.turn_passed = 0;
        this.row = row;
        this.col = col;
    }

    public abstract void Action(Organism[][] grid);
    public abstract void Move(Organism[][] grid);


    public void setAxis(int row, int col)
    {
        this.row = row;
        this.col = col;
    }

    public boolean availableCell(Organism[][] grid, int target_row, int target_col)
    {
        return (target_row < grid.length && target_row >= 0 && target_col >= 0 && target_col < grid[0].length);
    }
}
