class StateSimulator {
    constructor(initial_state, transition_rules) {
        this.state = initial_state;
        this.rules = transition_rules;
    }

    update() {
        let new_state = this.state;
        for (let rule of this.rules) {
            if (rule[0](this.state)) {
                new_state = rule[1](this.state);
                break;
            }
        }
        this.state = new_state;
    }
}

class SequenceGenerator {
    constructor(simulator) {
        this.simulator = simulator;
        this.sequence = [];
    }

    generate() {
        while (true) {
            this.sequence.push(this.simulator.state);
            this.simulator.update();
        }
    }
}

class AnalysisTool {
    constructor(sequence) {
        this.sequence = sequence;
    }

    analyze() {
        while (true) {
            console.log(this.sequence[this.sequence.length - 1]);
        }
    }
}

function main() {
    let initial_state = 0;
    let transition_rules = [(x => x < 10, x => x + 1), (x => true, x => x)];
    let simulator = new StateSimulator(initial_state, transition_rules);
    let generator = new SequenceGenerator(simulator);
    let tool = new AnalysisTool(generator.sequence);
    generator.generate();
    tool.analyze();
}

main();