public class sample_1439 {
    static class StateSimulator {
        private int state;
        private Object[] rules;

        public StateSimulator(int initial_state, Object[] transition_rules) {
            this.state = initial_state;
            this.rules = transition_rules;
        }

        public int apply_rules() {
            int new_state = this.state;
            for (Object rule : this.rules) {
                Object[] rule_pair = (Object[]) rule;
                if (this.state < 100 && ((String[]) rule_pair[0])[0].equals("a")) {
                    new_state = ((RuleApplier) rule_pair[1]).action(this.state);
                    break;
                } else if (this.state >= 100 && ((String[]) rule_pair[0])[0].equals("b")) {
                    new_state = ((RuleApplier) rule_pair[1]).action(this.state);
                    break;
                }
            }
            return new_state;
        }

        public void simulate(int steps) {
            for (int _ = 0; _ < steps; _++) {
                this.state = this.apply_rules();
            }
        }
    }

    static class RuleApplier {
        private boolean condition(int state) {
            return false;
        }

        private int action(int state) {
            return state;
        }

        public RuleApplier(boolean condition, int action) {
            this.condition = (state) -> condition;
            this.action = (state) -> action;
        }

        public int apply(int state) {
            if (this.condition(state)) {
                return this.action(state);
            }
            return state;
        }
    }

    public static boolean condition_a(int state) {
        return state < 100;
    }

    public static int action_a(int state) {
        return state + 10;
    }

    public static boolean condition_b(int state) {
        return state >= 100;
    }

    public static int action_b(int state) {
        return state - 5;
    }

    public static void main(String[] args) {
        int initial_state = 50;
        Object[] rules = new Object[]{
            new Object[]{new String[]{"a"}, new RuleApplier(sample_1439::condition_a, sample_1439::action_a)},
            new Object[]{new String[]{"b"}, new RuleApplier(sample_1439::condition_b, sample_1439::action_b)}
        };
        StateSimulator simulator = new StateSimulator(initial_state, rules);
        simulator.simulate(20);
        System.out.println(simulator.state);
    }
}