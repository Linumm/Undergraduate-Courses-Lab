package Week14.Practice2;
import java.util.ArrayList;

public class PriorityQueue<T> {
    private ArrayList<T> item;
    private ArrayList<Integer> priority;
    public PriorityQueue()
    {
        item = new ArrayList<T>();
        priority = new ArrayList<Integer>();
    }
    public void add(T value, int priority)
    {
        if (this.item.isEmpty()) {
            this.item.add(value);
            this.priority.add(priority);
            return;
        }
        for (int i=0; i<this.priority.size(); i++) {
            if (priority >= this.priority.get(i)) {
                this.priority.add(i, priority);
                this.item.add(i, value);
                return;
            }
        }
        this.priority.add(this.priority.size(), priority);
        this.item.add(this.item.size(), value);
    }
    public T remove()
    {
        if (this.item.isEmpty()) {
            return null;
        }
        T return_val = this.item.get(0);
        this.item.remove(0);
        this.priority.remove(0);

        return return_val;
    }

}
