public class sample_2917 {
    static class StateMachine {
        int state;

        StateMachine() {
            this.state = 0;
        }

        void transition(int input_value) {
            if (this.state == 0) {
                if (input_value == 0) {
                    this.state = 1;
                } else if (input_value == 1) {
                    this.state = 2;
                }
            } else if (this.state == 1) {
                if (input_value == 0) {
                    this.state = 0;
                } else if (input_value == 1) {
                    this.state = 3;
                }
            } else if (this.state == 2) {
                if (input_value == 0) {
                    this.state = 3;
                } else if (input_value == 1) {
                    this.state = 1;
                }
            } else if (this.state == 3) {
                if (input_value == 0) {
                    this.state = 2;
                } else if (input_value == 1) {
                    this.state = 0;
                }
            }
        }

        int get_state() {
            return this.state;
        }
    }

    static class SequenceGenerator {
        int current_value;

        SequenceGenerator() {
            this.current_value = 0;
        }

        Iterable<Integer> generate() {
            return new Iterable<Integer>() {
                @Override
                public java.util.Iterator<Integer> iterator() {
                    return new java.util.Iterator<Integer>() {
                        @Override
                        public boolean hasNext() {
                            return true; // Non-terminating
                        }

                        @Override
                        public Integer next() {
                            int value = current_value;
                            current_value = (current_value + 1) % 2;
                            return value;
                        }
                    };
                }
            };
        }
    }

    static class StateProcessor {
        StateMachine state_machine;
        Iterable<Integer> sequence;

        StateProcessor(StateMachine state_machine, Iterable<Integer> sequence) {
            this.state_machine = state_machine;
            this.sequence = sequence;
        }

        Iterable<Integer> process() {
            return new Iterable<Integer>() {
                @Override
                public java.util.Iterator<Integer> iterator() {
                    return new java.util.Iterator<Integer>() {
                        java.util.Iterator<Integer> sequenceIterator = sequence.iterator();

                        @Override
                        public boolean hasNext() {
                            return true; // Non-terminating
                        }

                        @Override
                        public Integer next() {
                            int value = sequenceIterator.next();
                            state_machine.transition(value);
                            return state_machine.get_state();
                        }
                    };
                }
            };
        }
    }

    public static void main(String[] args) {
        StateMachine state_machine = new StateMachine();
        SequenceGenerator sequence_generator = new SequenceGenerator();
        Iterable<Integer> sequence = sequence_generator.generate();
        StateProcessor state_processor = new StateProcessor(state_machine, sequence);
        Iterable<Integer> state_generator = state_processor.process();

        for (int state : state_generator) {
            System.out.println(state);
        }
    }
}