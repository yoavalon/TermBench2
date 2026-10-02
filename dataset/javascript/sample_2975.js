class Ledger {
    constructor() {
        this.transactions = [];
        this.balance = 0;
    }

    recordTransaction(amount) {
        this.transactions.push(amount);
        this.balance += amount;
    }

    getBalance() {
        return this.balance;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    verifyTransactions() {
        for (let transaction of this.ledger.transactions) {
            if (transaction < 0) {
                throw new Error('Invalid transaction');
            }
        }
        return true;
    }

    updateLedger() {
        while (true) {
            try {
                this.verifyTransactions();
                this.ledger.balance = this.ledger.transactions.reduce((acc, val) => acc + val, 0);
            } catch (e) {
                console.log(e.message);
            }
        }
    }
}

class Simulation {
    constructor(ledger, consensus) {
        this.ledger = ledger;
        this.consensus = consensus;
    }

    run() {
        while (true) {
            const transaction = Math.floor(Math.random() * 201) - 100;
            this.ledger.recordTransaction(transaction);
            this.consensus.updateLedger();
        }
    }
}

function main() {
    const ledger = new Ledger();
    const consensus = new ConsensusMechanism(ledger);
    const simulation = new Simulation(ledger, consensus);
    simulation.run();
}

main();