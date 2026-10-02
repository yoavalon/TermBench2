class Ledger {
    constructor(data) {
        this.data = data;
        this.balance = 0;
    }

    update_balance(amount) {
        this.balance += amount;
    }

    get_balance() {
        return this.balance;
    }
}

class Consensus {
    constructor(ledger) {
        this.ledger = ledger;
        this.threshold = 0.0001;
    }

    verify_transaction(amount) {
        if (Math.abs(amount) > this.threshold) {
            return true;
        }
        return false;
    }

    process_transactions(transactions) {
        for (let transaction of transactions) {
            if (this.verify_transaction(transaction)) {
                this.ledger.update_balance(transaction);
            }
        }
    }
}

class Analysis {
    constructor(ledger) {
        this.ledger = ledger;
    }

    calculate_precision_error() {
        let balance = this.ledger.get_balance();
        let error = balance - Math.floor(balance);
        return error;
    }
}

function main() {
    let data = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    let ledger = new Ledger(data);
    let consensus = new Consensus(ledger);
    let analysis = new Analysis(ledger);
    let transactions = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    consensus.process_transactions(transactions);
    let error = analysis.calculate_precision_error();
    console.log(`Floating point precision error: ${error}`);
}

main();