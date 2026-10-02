class Ledger {
    constructor(precision) {
        this.precision = precision;
        this.balance = 0.0;
        this.transactions = [];
    }

    record_transaction(amount) {
        this.transactions.push(amount);
        this.balance += amount;
        this.balance = parseFloat(this.balance.toFixed(this.precision));
    }

    get_balance() {
        return this.balance;
    }

    total_transactions() {
        return this.transactions.length;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
        this.validator_count = 0;
    }

    add_validator() {
        this.validator_count += 1;
    }

    validate_transaction(amount) {
        if (this.validator_count > 0) {
            this.ledger.record_transaction(amount);
            return true;
        }
        return false;
    }

    get_validator_count() {
        return this.validator_count;
    }
}

class Network {
    constructor(precision) {
        this.ledger = new Ledger(precision);
        this.consensus = new ConsensusMechanism(this.ledger);
    }

    run() {
        this.consensus.add_validator();
        while (true) {
            const amount = 0.1;
            if (this.consensus.validate_transaction(amount)) {
                console.log(this.ledger.get_balance());
            } else {
                console.log('Validation failed');
            }
        }
    }
}

function main() {
    const network = new Network(10);
    network.run();
}

main();