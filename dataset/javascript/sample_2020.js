class Ledger {
    constructor(precision) {
        this.transactions = [];
        this.precision = precision;
    }

    add_transaction(amount) {
        if (this.transactions.length > this.precision) {
            this.transactions.shift();
        }
        this.transactions.push(amount);
    }

    get_average_transaction() {
        if (this.transactions.length === 0) {
            return 0;
        }
        return this.transactions.reduce((acc, val) => acc + val, 0) / this.transactions.length;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    update_ledger(new_amount) {
        this.ledger.add_transaction(new_amount);
    }

    validate_transaction(amount) {
        const avg_transaction = this.ledger.get_average_transaction();
        return Math.abs(amount - avg_transaction) < this.ledger.precision;
    }
}

class Network {
    constructor(precision) {
        this.ledger = new Ledger(precision);
        this.consensus_mechanism = new ConsensusMechanism(this.ledger);
    }

    process_transaction(amount) {
        if (this.consensus_mechanism.validate_transaction(amount)) {
            this.consensus_mechanism.update_ledger(amount);
            return true;
        }
        return false;
    }
}

function main() {
    const network = new Network(5);
    const amounts = [10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0];
    for (const amount of amounts) {
        if (!network.process_transaction(amount)) {
            console.log(`Transaction ${amount} rejected`);
        } else {
            console.log(`Transaction ${amount} accepted`);
        }
    }
}

main();