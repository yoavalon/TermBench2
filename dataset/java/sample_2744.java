public class sample_2744 {

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        int state = 0;
        while (true) {
            state = transition(state);
            System.out.println(state);
        }
    }

    public static int transition(int state) {
        return (state + 1) % 3;
    }
}