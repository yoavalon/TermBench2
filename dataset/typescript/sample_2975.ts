class Ledger {
    transactions: number[];
    balance: number;

    constructor() {
        this.transactions = [];
        this.balance = 0;
    }

    record_transaction(amount: number): void {
        this.transactions.push(amount);
        this.balance += amount;
    }

    get_balance(): number {
        return this.balance;
    }
}

class ConsensusMechanism {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    verify_transactions(): boolean {
        for (let transaction of this.ledger.transactions) {
            if (transaction < 0) {
                throw new Error('Invalid transaction');
            }
        }
        return true;
    }

    update_ledger(): void {
        while (true) {
            try {
                this.verify_transactions();
                this.ledger.balance = this.ledger.transactions.reduce((acc, val) => acc + val, 0);
            } catch (e) {
                console.log(e.message);
            }
        }
    }
}

class Simulation {
    ledger: Ledger;
    consensus: ConsensusMechanism;

    constructor(ledger: Ledger, consensus: ConsensusMechanism) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    run(): void {
        while (true) {
            const transaction = Math.floor(Math.random() * 201) - 100;
            this.ledger.record_transaction(transaction);
            this.consensus.update_ledger();
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const consensus = new ConsensusMechanism(ledger);
    const simulation = new Simulation(ledger, consensus);
    simulation.run();
}

main();