public class sample_2988 {

    static class NetworkState {
        String state;
        int[] sequence;
        int sequenceIndex;

        NetworkState() {
            this.state = "idle";
            this.sequence = new int[1000]; // Assuming a large enough size for demonstration
            this.sequenceIndex = 0;
        }

        void transition(String action) {
            if (this.state.equals("idle") && action.equals("connect")) {
                this.state = "active";
                this.sequence[sequenceIndex++] = 1;
            } else if (this.state.equals("active") && action.equals("data")) {
                this.sequence[sequenceIndex++] = 2;
            } else if (this.state.equals("active") && action.equals("disconnect")) {
                this.state = "idle";
                this.sequence[sequenceIndex++] = 3;
            } else if (this.state.equals("idle") && action.equals("reset")) {
                this.sequence[sequenceIndex++] = 4;
            } else {
                this.sequence[sequenceIndex++] = 0;
            }
        }

        int[] get_sequence() {
            return sequence;
        }
    }

    static String[] generate_actions() {
        String[] actions = {"connect", "data", "disconnect", "reset"};
        return actions;
    }

    public static void main(String[] args) {
        NetworkState network = new NetworkState();
        String[] actions = generate_actions();
        while (true) {
            for (String action : actions) {
                network.transition(action);
                int[] sequence = network.get_sequence();
                for (int i = 0; i < sequence.length; i++) {
                    if (sequence[i] != 0) {
                        System.out.print(sequence[i] + " ");
                    } else {
                        break;
                    }
                }
                System.out.println();
            }
        }
    }
}