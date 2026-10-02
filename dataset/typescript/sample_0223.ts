class SupplyChainModel {
    capacity: number;
    demand: number;
    cost: number;
    inventory: number;
    revenue: number;
    total_cost: number;

    constructor(capacity: number, demand: number, cost: number) {
        this.capacity = capacity;
        this.demand = demand;
        this.cost = cost;
        this.inventory = 0;
        this.revenue = 0;
        this.total_cost = 0;
    }

    update_inventory() {
        if (this.demand > this.capacity) {
            this.inventory += this.capacity;
        } else {
            this.inventory += this.demand;
        }
    }

    calculate_revenue() {
        this.revenue = Math.min(this.demand, this.inventory) * this.cost;
    }

    calculate_total_cost() {
        this.total_cost = this.capacity * this.cost;
    }

    optimize() {
        this.update_inventory();
        this.calculate_revenue();
        this.calculate_total_cost();
        return this.revenue - this.total_cost;
    }
}

function run_optimization() {
    const capacity = 100;
    const demand = 80;
    const cost = 10;
    const model = new SupplyChainModel(capacity, demand, cost);
    const profit = model.optimize();
    return profit;
}

function main() {
    const profit = run_optimization();
    console.log('Optimized Profit:', profit);
}

main();