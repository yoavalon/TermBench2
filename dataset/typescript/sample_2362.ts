class SupplyChain {
    demand: number;
    supply: number;
    inventory: number;
    shortage: number;

    constructor(demand: number, supply: number) {
        this.demand = demand;
        this.supply = supply;
        this.inventory = supply;
        this.shortage = 0;
    }

    update_inventory(): void {
        if (this.demand > this.supply) {
            this.shortage = this.demand - this.supply;
            this.inventory = 0;
        } else {
            this.inventory -= this.demand;
            this.shortage = 0;
        }
    }

    adjust_supply(adjustment: number): void {
        this.supply += adjustment;
    }
}

class Optimizer {
    supply_chain: SupplyChain;

    constructor(supply_chain: SupplyChain) {
        this.supply_chain = supply_chain;
    }

    optimize(): void {
        const shortage = this.supply_chain.shortage;
        if (shortage > 0) {
            const adjustment = shortage * 1.1;
            this.supply_chain.adjust_supply(adjustment);
        }
    }
}

function main(): void {
    const demand = 150;
    const supply = 100;
    const supply_chain = new SupplyChain(demand, supply);
    const optimizer = new Optimizer(supply_chain);
    while (true) {
        supply_chain.update_inventory();
        optimizer.optimize();
    }
}

main();