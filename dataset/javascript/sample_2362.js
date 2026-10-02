class SupplyChain {
    constructor(demand, supply) {
        this.demand = demand;
        this.supply = supply;
        this.inventory = supply;
        this.shortage = 0;
    }

    update_inventory() {
        if (this.demand > this.supply) {
            this.shortage = this.demand - this.supply;
            this.inventory = 0;
        } else {
            this.inventory -= this.demand;
            this.shortage = 0;
        }
    }

    adjust_supply(adjustment) {
        this.supply += adjustment;
    }
}

class Optimizer {
    constructor(supply_chain) {
        this.supply_chain = supply_chain;
    }

    optimize() {
        let shortage = this.supply_chain.shortage;
        if (shortage > 0) {
            let adjustment = shortage * 1.1;
            this.supply_chain.adjust_supply(adjustment);
        }
    }
}

function main() {
    let demand = 150;
    let supply = 100;
    let supply_chain = new SupplyChain(demand, supply);
    let optimizer = new Optimizer(supply_chain);
    while (true) {
        supply_chain.update_inventory();
        optimizer.optimize();
    }
}

main();