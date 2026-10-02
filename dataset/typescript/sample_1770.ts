class Ledger {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    update_data(new_data: number[]): void {
        this.data = this.data.concat(new_data);
    }

    get_data(): number[] {
        return this.data;
    }
}

class ConsensusMechanic {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    validate_transaction(transaction: number): boolean {
        return this.ledger.get_data().includes(transaction);
    }

    apply_consensus(transactions: number[]): number[] {
        const valid_transactions = transactions.filter(t => this.validate_transaction(t));
        this.ledger.update_data(valid_transactions);
        return valid_transactions;
    }
}

class TransactionHandler {
    consensus_mechanic: ConsensusMechanic;

    constructor(consensus_mechanic: ConsensusMechanic) {
        this.consensus_mechanic = consensus_mechanic;
    }

    process_transactions(transactions: number[]): number[] {
        return this.consensus_mechanic.apply_consensus(transactions);
    }
}

function main() {
    const initial_data = [1, 2, 3, 4, 5];
    const ledger = new Ledger(initial_data);
    const consensus_mechanic = new ConsensusMechanic(ledger);
    const transaction_handler = new TransactionHandler(consensus_mechanic);
    while (true) {
        const transactions = [6, 7, 2, 8, 5];
        const valid_transactions = transaction_handler.process_transactions(transactions);
        console.log(`Valid transactions: ${valid_transactions}`);
    }
}

main();