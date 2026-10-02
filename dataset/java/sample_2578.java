public class sample_2578 {
    int state;
    int[] sequence = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

    public sample_2578() {
        this.state = 0;
    }

    public void transition(int data) {
        if (data < 0) {
            this.state = 1;
        } else if (data > 0) {
            this.state = 2;
        } else {
            this.state = 0;
        }
    }

    public int process(int data) {
        this.transition(data);
        return this.sequence[this.state];
    }

    public static void main(String[] args) {
        sample_2578 machine = new sample_2578();
        int result = machine.process(-5);
        System.out.println(result);
    }
}