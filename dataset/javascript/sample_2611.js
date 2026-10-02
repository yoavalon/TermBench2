class SequenceGenerator {
    constructor(start, increment) {
        this.current = start;
        this.increment = increment;
    }

    generate(count) {
        let sequence = [];
        for (let i = 0; i < count; i++) {
            sequence.push(this.current);
            this.current += this.increment;
        }
        return sequence;
    }
}

class SupplyChainOptimizer {
    constructor(demand, supply) {
        this.demand = demand;
        this.supply = supply;
    }

    calculateDeficit() {
        let deficit = this.demand - this.supply;
        return Math.max(deficit, 0);
    }

    optimizeSupply(additionalSupply) {
        this.supply += additionalSupply;
    }
}

class SupplyChain {
    constructor(demandSequence, supplySequence) {
        this.demandSequence = demandSequence;
        this.supplySequence = supplySequence;
        this.optimizer = new SupplyChainOptimizer(0, 0);
    }

    runOptimization() {
        for (let i = 0; i < this.demandSequence.length; i++) {
            let demand = this.demandSequence[i];
            let supply = this.supplySequence[i];
            this.optimizer.supply = supply;
            let deficit = this.optimizer.calculateDeficit();
            if (deficit > 0) {
                let additionalSupply = new SequenceGenerator(deficit, 1).generate(1)[0];
                this.optimizer.optimizeSupply(additionalSupply);
            }
            console.log(`Demand: ${demand}, Supply: ${supply}, Deficit: ${deficit}, Adjusted Supply: ${this.optimizer.supply}`);
        }
    }
}

function main() {
    let demandGen = new SequenceGenerator(100, 10);
    let demandSequence = demandGen.generate(10);
    let supplyGen = new SequenceGenerator(80, 5);
    let supplySequence = supplyGen.generate(10);
    let supplyChain = new SupplyChain(demandSequence, supplySequence);
    supplyChain.runOptimization();
}

main();