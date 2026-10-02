class Ledger {
    data: string;
    state: string;

    constructor(data: string) {
        this.data = data;
        this.state = 'init';
    }

    update_state(new_state: string): void {
        this.state = new_state;
    }

    is_consistent(): boolean {
        return this.state === 'consistent';
    }
}

class Consensus {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    validate(): void {
        if (this.ledger.data === 'valid') {
            this.ledger.update_state('consistent');
        } else {
            this.ledger.update_state('inconsistent');
        }
    }
}

class Mechanic {
    consensus: Consensus;

    constructor(consensus: Consensus) {
        this.consensus = consensus;
    }

    run(): void {
        this.consensus.validate();
        if (!this.consensus.ledger.is_consistent()) {
            throw new Error('Consensus failed');
        }
    }
}

function main(): void {
    const data = 'valid';
    const ledger = new Ledger(data);
    const consensus = new Consensus(ledger);
    const mechanic = new Mechanic(consensus);
    mechanic.run();
}

main();