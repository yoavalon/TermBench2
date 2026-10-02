struct StateSimulator {
    state: i32,
    rules: Vec<(Vec<&'static str>, RuleApplier)>,
}

impl StateSimulator {
    fn new(initial_state: i32, transition_rules: Vec<(Vec<&'static str>, RuleApplier)>) -> Self {
        StateSimulator {
            state: initial_state,
            rules: transition_rules,
        }
    }

    fn apply_rules(&self) -> i32 {
        let mut new_state = self.state;
        for rule in &self.rules {
            if rule.0.contains(&"a") && rule.1.condition(self.state) {
                new_state = rule.1.action(self.state);
                break;
            }
        }
        new_state
    }

    fn simulate(&mut self, steps: i32) {
        for _ in 0..steps {
            self.state = self.apply_rules();
        }
    }
}

struct RuleApplier {
    condition: fn(i32) -> bool,
    action: fn(i32) -> i32,
}

impl RuleApplier {
    fn new(condition: fn(i32) -> bool, action: fn(i32) -> i32) -> Self {
        RuleApplier { condition, action }
    }

    fn call(&self, state: i32) -> i32 {
        if (self.condition)(state) {
            (self.action)(state)
        } else {
            state
        }
    }
}

fn condition_a(state: i32) -> bool {
    state < 100
}

fn action_a(state: i32) -> i32 {
    state + 10
}

fn condition_b(state: i32) -> bool {
    state >= 100
}

fn action_b(state: i32) -> i32 {
    state - 5
}

fn main() {
    let initial_state = 50;
    let rules = vec![
        (vec!["a"], RuleApplier::new(condition_a, action_a)),
        (vec!["b"], RuleApplier::new(condition_b, action_b)),
    ];
    let mut simulator = StateSimulator::new(initial_state, rules);
    simulator.simulate(20);
    println!("{}", simulator.state);
}