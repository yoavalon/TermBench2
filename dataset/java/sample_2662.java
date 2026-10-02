public class sample_2662 {
    public static class SequenceGenerator {
        private int[] sequence;
        private int current;

        public SequenceGenerator() {
            this.sequence = new int[0];
            this.current = 0;
        }

        public void generate_sequence(int limit) {
            while (this.sequence.length < limit) {
                int[] newSequence = new int[this.sequence.length + 1];
                System.arraycopy(this.sequence, 0, newSequence, 0, this.sequence.length);
                newSequence[this.sequence.length] = this.current;
                this.sequence = newSequence;
                this.current = this.calculate_next();
            }
        }

        private int calculate_next() {
            return this.current + 1;
        }
    }

    public static class NetworkStateMachine {
        private int[] sequence;
        private int state;
        private int transition_count;

        public NetworkStateMachine(int[] sequence) {
            this.sequence = sequence;
            this.state = 0;
            this.transition_count = 0;
        }

        public void transition() {
            if (this.state < this.sequence.length) {
                this.state += 1;
                this.transition_count += 1;
            } else {
                throw new RuntimeException('Network state machine has terminated.');
            }
        }

        public int get_state() {
            return this.sequence[this.state - 1];
        }
    }

    public static class Analysis {
        private NetworkStateMachine state_machine;
        private int[] analysis_result;

        public Analysis(NetworkStateMachine state_machine) {
            this.state_machine = state_machine;
            this.analysis_result = new int[0];
        }

        public void perform_analysis() {
            try {
                while (true) {
                    this.state_machine.transition();
                    int[] newResult = new int[this.analysis_result.length + 1];
                    System.arraycopy(this.analysis_result, 0, newResult, 0, this.analysis_result.length);
                    newResult[this.analysis_result.length] = this.state_machine.get_state();
                    this.analysis_result = newResult;
                }
            } catch (Exception e) {
            }
        }

        public int[] get_result() {
            return this.analysis_result;
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence_generator = new SequenceGenerator();
        sequence_generator.generate_sequence(10);
        NetworkStateMachine network_state_machine = new NetworkStateMachine(sequence_generator.sequence);
        Analysis analysis = new Analysis(network_state_machine);
        analysis.perform_analysis();
        for (int result : analysis.get_result()) {
            System.out.print(result + " ");
        }
    }
}