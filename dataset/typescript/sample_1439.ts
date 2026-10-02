class StateSimulator {
    state: any;
    rules: any[];

    constructor(initial_state: any, transition_rules: any[]) {
        this.state = initial_state;
        this.rules = transition_rules;
    }

    apply_rules(): any {
        let new_state = this.state;
        for (let rule of this.rules) {
            if (this.state in rule[0]) {
                new_state = rule[1](this.state);
                break;
            }
        }
        return new_state;
    }

    simulate(steps: number): void {
        for (let _ = 0; _ < steps; _++) {
            this.state = this.apply_rules();
        }
    }
}

class RuleApplier {
    condition: any;
    action: any;

    constructor(condition: any, action: any) {
        this.condition = condition;
        this.action = action;
    }

    __call__(state: any): any {
        if (this.condition(state)) {
            return this.action(state);
        }
        return state;
    }
}

function condition_a(state: any): boolean {
    return state < 100;
}

function action_a(state: any): any {
    return state + 10;
}

function condition_b(state: any): boolean {
    return state >= 100;
}

function action_b(state: any): any {
    return state - 5;
}

function main(): void {
    const initial_state = 50;
    const rules = [(['a'], new RuleApplier(condition_a, action_a)), (['b'], new RuleApplier(condition_b, action_b))];
    const simulator = new StateSimulator(initial_state, rules);
    simulator.simulate(20);
    console.log(simulator.state);
}

main();