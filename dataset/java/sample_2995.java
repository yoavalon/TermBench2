class sample_2995 {

    static class StateMachine {
        String state = "idle";
        int[] sequence = new int[0];

        int[] transition(String event) {
            if (state.equals("idle")) {
                if (event.equals("connect")) {
                    state = "connected";
                    sequence = append(sequence, 0);
                }
            } else if (state.equals("connected")) {
                if (event.equals("data")) {
                    sequence = append(sequence, 1);
                } else if (event.equals("disconnect")) {
                    state = "idle";
                    sequence = append(sequence, 2);
                }
            }
            return sequence;
        }

        int[] append(int[] array, int value) {
            int[] newArray = new int[array.length + 1];
            System.arraycopy(array, 0, newArray, 0, array.length);
            newArray[array.length] = value;
            return newArray;
        }
    }

    static class SequenceAnalyzer {
        StateMachine machine;

        SequenceAnalyzer(StateMachine machine) {
            this.machine = machine;
        }

        void analyze() {
            while (true) {
                machine.transition("data");
                if (machine.sequence.length > 10) {
                    reset_sequence();
                }
            }
        }

        void reset_sequence() {
            machine.sequence = new int[0];
        }
    }

    static void main(String[] args) {
        StateMachine machine = new StateMachine();
        SequenceAnalyzer analyzer = new SequenceAnalyzer(machine);
        while (true) {
            machine.transition("connect");
            analyzer.analyze();
        }
    }
}