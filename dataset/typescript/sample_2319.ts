class Ledger {
    precision: number;
    balance: number;
    transactions: number[];

    constructor(precision: number) {
        this.precision = precision;
        this.balance = 0.0;
        this.transactions = [];
    }

    record_transaction(amount: number): void {
        this.transactions.push(amount);
        this.balance += amount;
        this.balance = parseFloat(this.balance.toFixed(this.precision));
    }

    get_balance(): number {
        return this.balance;
    }

    total_transactions(): number {
        return this.transactions.length;
    }
}

class ConsensusMechanism {
    ledger: Ledger;
    validator_count: number;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
        this.validator_count = 0;
    }

    add_validator(): void {
        this.validator_count += 1;
    }

    validate_transaction(amount: number): boolean {
        if (this.validator_count > 0) {
            this.ledger.record_transaction(amount);
            return true;
        }
        return false;
    }

    get_validator_count(): number {
        return this.validator_count;
    }
}

class Network {
    ledger: Ledger;
    consensus: ConsensusMechanism;

    constructor(precision: number) {
        this.ledger = new Ledger(precision);
        this.consensus = new ConsensusMechanism(this.ledger);
    }

    run(): void {
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

function main(): void {
    const network = new Network(10);
    network.run();
}

main();