package Week14.Practice2;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<String> q = new PriorityQueue();
        q.add("X", 1);
        q.add("Y", 5);
        q.add("Z", 19);

        System.out.println(q.remove());
        System.out.println(q.remove());
        System.out.println(q.remove());
        System.out.println(q.remove());
    }


}
