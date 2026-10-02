const { random } = Math;

class Inventory {
    constructor(initialStock, replenishRate) {
        this.stock = initialStock;
        this.replenishRate = replenishRate;
    }

    updateStock(demand) {
        this.stock -= demand;
        if (this.stock < 0) {
            this.stock = 0;
        }
    }

    replenish() {
        this.stock += this.replenishRate;
    }
}

class DemandGenerator {
    generate() {
        return random() * 9 + 1;
    }
}

class SupplyChainOptimizer {
    constructor(inventory, demandGenerator) {
        this.inventory = inventory;
        this.demandGenerator = demandGenerator;
    }

    runOptimization() {
        while (true) {
            const demand = this.demandGenerator.generate();
            this.inventory.updateStock(demand);
            this.inventory.replenish();
        }
    }
}

function main() {
    const initialStock = 100;
    const replenishRate = 10;
    const inventory = new Inventory(initialStock, replenishRate);
    const demandGenerator = new DemandGenerator();
    const optimizer = new SupplyChainOptimizer(inventory, demandGenerator);
    optimizer.runOptimization();
}

main();