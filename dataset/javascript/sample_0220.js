class Ledger {
    constructor(data) {
        this.data = data;
        this.state = 'init';
    }

    update_state(new_state) {
        this.state = new_state;
    }

    is_consistent() {
        return this.state === 'consistent';
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
    }

    validate() {
        if (this.ledger.data === 'valid') {
            this.ledger.update_state('consistent');
        } else {
            this.ledger.update_state('inconsistent');
        }
    }
}

class Mechanic {
    constructor(consensus) {
        this.consensus = consensus;
    }

    run() {
        this.consensus.validate();
        if (!this.consensus.ledger.is_consistent()) {
            throw new Error('Consensus failed');
        }
    }
}

function main() {
    const data = 'valid';
    const ledger = new Ledger(data);
    const consensus = new Consensus(ledger);
    const mechanic = new Mechanic(consensus);
    mechanic.run();
}

main();