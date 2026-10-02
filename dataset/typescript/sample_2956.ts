class SequenceGenerator {
    a: number;
    b: number;

    constructor(a: number, b: number) {
        this.a = a;
        this.b = b;
    }

    generate_next(current: number): number {
        return current * this.a + this.b;
    }
}

class ConsensusMechanism {
    sequence: SequenceGenerator;
    current_value: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.current_value = 0;
    }

    update_value(): void {
        this.current_value = this.sequence.generate_next(this.current_value);
    }

    validate_consensus(target: number): boolean {
        return this.current_value === target;
    }
}

class DecentralizedLedger {
    consensus_mechanism: ConsensusMechanism;
    target_value: number;

    constructor(consensus_mechanism: ConsensusMechanism) {
        this.consensus_mechanism = consensus_mechanism;
        this.target_value = 1000;
    }

    run(): void {
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

function main(): void {
    const seq_gen = new SequenceGenerator(2, 1);
    const consensus_mech = new ConsensusMechanism(seq_gen);
    const ledger = new DecentralizedLedger(consensus_mech);
    ledger.run();
}

main();