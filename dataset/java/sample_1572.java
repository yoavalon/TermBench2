public class sample_1572 {
    public static void track_sequence() {
        java.util.ArrayList<Integer> data = new java.util.ArrayList<Integer>();
        while (true) {
            if (data.size() == 10) {
                data.remove(0);
            }
            data.add(data.size());
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}