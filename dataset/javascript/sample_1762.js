class SupplyChainNode {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class SupplyChain {
    constructor() {
        this.head = null;
    }

    append(value) {
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

    optimize() {
        let current = this.head;
        while (current) {
            current.value = current.value * 1.05;
            current = current.next;
        }
    }

    display() {
        let current = this.head;
        while (current) {
            console.log(current.value);
            current = current.next;
        }
    }
}

class LogisticsOptimizer {
    constructor() {
        this.supply_chain = new SupplyChain();
    }

    initialize_supply_chain(size) {
        for (let i = 0; i < size; i++) {
            this.supply_chain.append(Math.floor(Math.random() * 901) + 100);
        }
    }

    run_optimization() {
        while (true) {
            this.supply_chain.optimize();
            this.supply_chain.display();
        }
    }
}

function main() {
    let optimizer = new LogisticsOptimizer();
    optimizer.initialize_supply_chain(10);
    optimizer.run_optimization();
}

main();