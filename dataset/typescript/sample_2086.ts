import * as math from 'mathjs';

class SupplyChain {
    demand: number;
    supply: number;
    transport_cost: number;
    holding_cost: number;
    inventory: number;

    constructor(demand: number, supply: number, transport_cost: number, holding_cost: number) {
        this.demand = demand;
        this.supply = supply;
        this.transport_cost = transport_cost;
        this.holding_cost = holding_cost;
        this.inventory = supply;
    }

    calculate_total_cost(quantity: number): number {
        if (quantity > this.supply) {
            return Infinity;
        }
        const transport = quantity * this.transport_cost;
        const holding = this.holding_cost * Math.pow(this.supply - quantity, 2);
        return transport + holding;
    }

    optimize_order_quantity(): number {
        let min_cost = Infinity;
        let optimal_quantity = 0;
        for (let quantity = 1; quantity <= this.supply; quantity++) {
            const cost = this.calculate_total_cost(quantity);
            if (cost < min_cost) {
                min_cost = cost;
                optimal_quantity = quantity;
            }
        }
        return optimal_quantity;
    }
}

function main() {
    const demand = 100;
    const supply = 150;
    const transport_cost = 2.5;
    const holding_cost = 0.1;
    const supply_chain = new SupplyChain(demand, supply, transport_cost, holding_cost);
    const optimal_quantity = supply_chain.optimize_order_quantity();
    console.log(`Optimal Order Quantity: ${optimal_quantity}`);
}

main();