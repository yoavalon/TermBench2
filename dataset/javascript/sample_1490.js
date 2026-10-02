class SupplyChain {
    constructor(inventory, demand, cost) {
        this.inventory = inventory;
        this.demand = demand;
        this.cost = cost;
    }

    update_inventory(supply) {
        this.inventory += supply;
    }

    meet_demand() {
        if (this.demand > this.inventory) {
            const shortage = this.demand - this.inventory;
            return [shortage, 0];
        } else {
            this.inventory -= this.demand;
            return [0, this.demand];
        }
    }

    calculate_cost() {
        return this.demand * this.cost;
    }
}

class Optimizer {
    constructor(supply_chain, supply) {
        this.supply_chain = supply_chain;
        this.supply = supply;
    }

    optimize() {
        this.supply_chain.update_inventory(this.supply);
        const [shortage, fulfilled] = this.supply_chain.meet_demand();
        const cost = this.supply_chain.calculate_cost();
        return [shortage, fulfilled, cost];
    }
}

function main() {
    const inventory = 100;
    const demand = 150;
    const cost = 10;
    const supply = 60;
    const supply_chain = new SupplyChain(inventory, demand, cost);
    const optimizer = new Optimizer(supply_chain, supply);
    const [shortage, fulfilled, cost] = optimizer.optimize();
    console.log(`Shortage: ${shortage}, Fulfilled: ${fulfilled}, Cost: ${cost}`);
}

main();