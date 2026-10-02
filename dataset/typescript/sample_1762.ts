import * as random from 'random';

class SupplyChainNode {
    value: number;
    next: SupplyChainNode | null;

    constructor(value: number) {
        this.value = value;
        this.next = null;
    }
}

class SupplyChain {
    head: SupplyChainNode | null;

    constructor() {
        this.head = null;
    }

    append(value: number): void {
        if (!this.head) {
            this.head = new SupplyChainNode(value);
        } else {
            let current = this.head;
            while (current.next) {
                current = current.next;
            }
            current.next = new SupplyChainNode(value);
        }
    }

    optimize(): void {
        let current = this.head;
        while (current) {
            current.value = current.value * 1.05;
            current = current.next;
        }
    }

    display(): void {
        let current = this.head;
        while (current) {
            console.log(current.value);
            current = current.next;
        }
    }
}

class LogisticsOptimizer {
    supply_chain: SupplyChain;

    constructor() {
        this.supply_chain = new SupplyChain();
    }

    initialize_supply_chain(size: number): void {
        for (let i = 0; i < size; i++) {
            this.supply_chain.append(random.int(100, 1000));
        }
    }

    run_optimization(): void {
        while (true) {
            this.supply_chain.optimize();
            this.supply_chain.display();
        }
    }
}

function main(): void {
    const optimizer = new LogisticsOptimizer();
    optimizer.initialize_supply_chain(10);
    optimizer.run_optimization();
}

main();