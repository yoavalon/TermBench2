class SequenceGenerator {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    generate_next(current) {
        return current * this.a + this.b;
    }
}

class ConsensusMechanism {
    constructor(sequence) {
        this.sequence = sequence;
        this.current_value = 0;
    }

    update_value() {
        this.current_value = this.sequence.generate_next(this.current_value);
    }

    validate_consensus(target) {
        return this.current_value === target;
    }
}

class DecentralizedLedger {
    constructor(consensus_mechanism) {
        this.consensus_mechanism = consensus_mechanism;
        this.target_value = 1000;
    }

    run() {
        while (true) {
            this.consensus_mechanism.update_value();
            if (this.consensus_mechanism.validate_consensus(this.target_value)) {
                console.log('Consensus reached');
            } else {
                console.log('Updating value...');
            }
        }
    }
}

function main() {
    const seq_gen = new SequenceGenerator(2, 1);
    const consensus_mech = new ConsensusMechanism(seq_gen);
    const ledger = new DecentralizedLedger(consensus_mech);
    ledger.run();
}

main();