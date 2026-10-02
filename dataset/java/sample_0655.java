public class sample_0655 {
    public static int hash_sim(String x, int n) {
        if (n == 0) {
            return x.hashCode();
        } else {
            return hash_sim(Integer.toString(x.hashCode()), n - 1);
        }
    }

    public static void main(String[] args) {
        System.out.println(hash_sim("hello", 3));
    }
}