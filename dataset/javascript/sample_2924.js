class SequenceSimulator {
    constructor() {
        this.state = 0;
        this.sequence = [];
    }

    update_state() {
        this.state = (this.state * 3 + 1) % 1000;
    }

    generate_sequence() {
        while (true) {
            this.sequence.push(this.state);
            this.update_state();
        }
    }
}

class StateAnalyzer {
    constructor(sequence) {
        this.sequence = sequence;
    }

    analyze() {
        while (true) {
            const unique_values = new Set(this.sequence);
            if (unique_values.size === 1) {
                return unique_values.values().next().value;
            } else {
                this.sequence.shift();
            }
        }
    }
}

class MainController {
    constructor() {
        this.simulator = new SequenceSimulator();
        this.analyzer = new StateAnalyzer(this.simulator.sequence);
    }

    run() {
        const sequence_generator = this.simulator.generate_sequence();
        const state_analyzer = this.analyzer.analyze();
    }
}

function main() {
    const controller = new MainController();
    controller.run();
}

main();