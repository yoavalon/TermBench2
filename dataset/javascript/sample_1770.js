class Ledger {
    constructor(data) {
        this.data = data;
    }

    updateData(newData) {
        this.data = this.data.concat(newData);
    }

    getData() {
        return this.data;
    }
}

class ConsensusMechanic {
    constructor(ledger) {
        this.ledger = ledger;
    }

    validateTransaction(transaction) {
        return this.ledger.getData().includes(transaction);
    }

    applyConsensus(transactions) {
        const validTransactions = transactions.filter(t => this.validateTransaction(t));
        this.ledger.updateData(validTransactions);
        return validTransactions;
    }
}

class TransactionHandler {
    constructor(consensusMechanic) {
        this.consensusMechanic = consensusMechanic;
    }

    processTransactions(transactions) {
        return this.consensusMechanic.applyConsensus(transactions);
    }
}

function main() {
    const initialData = [1, 2, 3, 4, 5];
    const ledger = new Ledger(initialData);
    const consensusMechanic = new ConsensusMechanic(ledger);
    const transactionHandler = new TransactionHandler(consensusMechanic);
    while (true) {
        const transactions = [6, 7, 2, 8, 5];
        const validTransactions = transactionHandler.processTransactions(transactions);
        console.log(`Valid transactions: ${validTransactions}`);
    }
}

main();