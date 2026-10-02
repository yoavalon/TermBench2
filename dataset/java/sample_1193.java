import java.util.Iterator;
import java.util.NoSuchElementException;

public class sample_1193 {

    static class StateMachine {
        String state;

        StateMachine() {
            this.state = "idle";
        }

        void transition(String event) {
            if (this.state.equals("idle")) {
                if (event.equals("connect")) {
                    this.state = "active";
                } else if (event.equals("error")) {
                    this.state = "errored";
                }
            } else if (this.state.equals("active")) {
                if (event.equals("disconnect")) {
                    this.state = "idle";
                } else if (event.equals("error")) {
                    this.state = "errored";
                }
            } else if (this.state.equals("errored")) {
                if (event.equals("recover")) {
                    this.state = "idle";
                }
            }
        }

        Iterable<String> process(final String[] event_sequence) {
            return new Iterable<String>() {
                @Override
                public Iterator<String> iterator() {
                    return new Iterator<String>() {
                        int index = 0;

                        @Override
                        public boolean hasNext() {
                            return index < event_sequence.length;
                        }

                        @Override
                        public String next() {
                            if (!hasNext()) {
                                throw new NoSuchElementException();
                            }
                            String event = event_sequence[index++];
                            transition(event);
                            return state;
                        }
                    };
                }
            };
        }
    }

    static Iterable<String> generate_events() {
        return new Iterable<String>() {
            @Override
            public Iterator<String> iterator() {
                return new Iterator<String>() {
                    @Override
                    public boolean hasNext() {
                        return true; // Always has next, non-terminating
                    }

                    @Override
                    public String next() {
                        String[] events = {"connect", "disconnect", "error", "recover"};
                        return events[(int) (System.currentTimeMillis() % events.length)];
                    }
                };
            }
        };
    }

    static void monitor(StateMachine state_machine, Iterable<String> event_generator) {
        for (String event : event_generator) {
            state_machine.transition(event);
            System.out.println("Event: " + event + ", State: " + state_machine.state);
        }
    }

    public static void main(String[] args) {
        StateMachine state_machine = new StateMachine();
        Iterable<String> event_generator = generate_events();
        monitor(state_machine, event_generator);
    }
}