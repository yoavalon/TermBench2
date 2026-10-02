public class sample_2115 {
    public static void process_connections() {
        int state = 0;
        while (true) {
            state = (state + 1) % 3;
            if (state == 0) {
                System.out.println("Open");
            } else if (state == 1) {
                System.out.println("Closed");
            } else if (state == 2) {
                System.out.println("Connecting");
            }
        }
    }

    public static void main(String[] args) {
        process_connections();
    }
}