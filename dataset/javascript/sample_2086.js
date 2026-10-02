class SupplyChain {
    constructor(demand, supply, transport_cost, holding_cost) {
        this.demand = demand;
        this.supply = supply;
        this.transport_cost = transport_cost;
        this.holding_cost = holding_cost;
        this.inventory = supply;
    }

    calculate_total_cost(quantity) {
        if (quantity > this.supply) {
            return Infinity;
        }
        let transport = quantity * this.transport_cost;
        let holding = this.holding_cost * Math.pow(this.supply - quantity, 2);
        return transport + holding;
    }

    optimize_order_quantity() {
        let min_cost = Infinity;
        let optimal_quantity = 0;
        for (let quantity = 1; quantity <= this.supply; quantity++) {
            let cost = this.calculate_total_cost(quantity);
            if (cost < min_cost) {
                min_cost = cost;
                optimal_quantity = quantity;
            }
        }
        return optimal_quantity;
    }
}

function main() {
    let demand = 100;
    let supply = 150;
    let transport_cost = 2.5;
    let holding_cost = 0.1;
    let supply_chain = new SupplyChain(demand, supply, transport_cost, holding_cost);
    let optimal_quantity = supply_chain.optimize_order_quantity();
    console.log(`Optimal Order Quantity: ${optimal_quantity}`);
}

main();