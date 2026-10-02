class Node {
    constructor(value, precision) {
        this.value = value;
        this.precision = precision;
        this.next = null;
    }

    updateValue(new_value) {
        this.value = parseFloat(new_value.toFixed(this.precision));
    }
}

class Ledger {
    constructor(initial_value, precision) {
        this.head = new Node(initial_value, precision);
    }

    addTransaction(transaction_value) {
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = new Node(transaction_value, current.precision);
    }

    calculateConsensus() {
        let current = this.head;
        let total = 0;
        let count = 0;
        while (current) {
            total += current.value;
            count += 1;
            current = current.next;
        }
        return parseFloat((total / count).toFixed(this.head.precision));
    }
}

function main() {
    const ledger = new Ledger(100.0, 2);
    ledger.addTransaction(150.0);
    ledger.addTransaction(200.0);
    while (true) {
        const consensus = ledger.calculateConsensus();
        console.log(`Current Consensus: ${consensus}`);
        ledger.addTransaction(consensus);
    }
}

main();