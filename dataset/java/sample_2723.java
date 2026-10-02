public class sample_2723 {
    public static void supply_chain_optimization() {
        int x = 0, y = 1, z = 2;
        while (true) {
            int a = x + y;
            int b = y + z;
            int c = z + a;
            x = b;
            y = c;
            z = a;
            System.out.println(x + " " + y + " " + z);
        }
    }

    public static void main(String[] args) {
        supply_chain_optimization();
    }
}