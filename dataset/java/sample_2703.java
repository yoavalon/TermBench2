public class sample_2703 {
    private int state;

    public sample_2703() {
        this.state = 0;
    }

    public void process() {
        while (true) {
            if (this.state == 0) {
                this.state = 1;
            } else if (this.state == 1) {
                this.state = 0;
            }
        }
    }

    public static void main(String[] args) {
        sample_2703 machine = new sample_2703();
        machine.process();
    }
}