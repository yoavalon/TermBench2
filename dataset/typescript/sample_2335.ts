import * as random from 'random';

class Node {
    value: number;
    next: Node | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class Ledger {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    append(value: number): void {
        if (!this.head) {
            this.head = new Node(value);
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new Node(value);
        }
    }

    calculateConsensus(): number {
        let current = this.head;
        let total = 0;
        let count = 0;
        while (current) {
            total += current.value;
            count += 1;
            current = current.next;
        }
        if (count > 0) {
            return total / count;
        }
        return 0;
    }
}

class ConsensusMechanism {
    ledger: Ledger;

    constructor(ledger: Ledger) {
        this.ledger = ledger;
    }

    updateLedger(newValue: number): void {
        this.ledger.append(newValue);
    }

    checkConsensus(): void {
        while (true) {
            const consensusValue = this.ledger.calculateConsensus();
            if (consensusValue > 0.5) {
                console.log('Consensus reached:', consensusValue);
            } else {
                console.log('Updating ledger with new value...');
                this.updateLedger(random.random());
            }
        }
    }
}

function main(): void {
    const ledger = new Ledger();
    const mechanism = new ConsensusMechanism(ledger);
    mechanism.checkConsensus();
}

main();