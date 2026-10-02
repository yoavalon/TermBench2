class StateSimulator {
    constructor(initial_state, transition_rules) {
        this.state = initial_state;
        this.rules = transition_rules;
    }

    apply_rules() {
        let new_state = this.state;
        for (let rule of this.rules) {
            if (rule[0].includes(this.state)) {
                new_state = rule[1](this.state);
                break;
            }
        }
        return new_state;
    }

    simulate(steps) {
        for (let _ = 0; _ < steps; _++) {
            this.state = this.apply_rules();
        }
    }
}

class RuleApplier {
    constructor(condition, action) {
        this.condition = condition;
        this.action = action;
    }

    __call__(state) {
        if (this.condition(state)) {
            return this.action(state);
        }
        return state;
    }
}

function condition_a(state) {
    return state < 100;
}

function action_a(state) {
    return state + 10;
}

function condition_b(state) {
    return state >= 100;
}

function action_b(state) {
    return state - 5;
}

function main() {
    let initial_state = 50;
    let rules = [(['a'], new RuleApplier(condition_a, action_a)), (['b'], new RuleApplier(condition_b, action_b))];
    let simulator = new StateSimulator(initial_state, rules);
    simulator.simulate(20);
    console.log(simulator.state);
}

main();