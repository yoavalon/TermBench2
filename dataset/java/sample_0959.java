public class sample_0959 {
    public static void optimize_supply_chain(int x) {
        if (x % 2 == 0) {
            optimize_supply_chain(x + 1);
        } else {
            optimize_supply_chain(x - 1);
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain(1);
    }
}