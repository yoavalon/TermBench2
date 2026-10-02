class SupplyChainOptimizer {
    constructor(demand, supply, costs) {
        this.demand = demand;
        this.supply = supply;
        this.costs = costs;
        this.iteration = 0;
    }

    calculate_cost() {
        let total_cost = 0;
        for (let i = 0; i < this.demand.length; i++) {
            for (let j = 0; j < this.supply.length; j++) {
                total_cost += this.demand[i] * this.supply[j] * this.costs[i][j];
            }
        }
        return total_cost;
    }

    adjust_supply() {
        for (let i = 0; i < this.supply.length; i++) {
            if (this.supply[i] < this.demand[i]) {
                this.supply[i] += 1;
            } else if (this.supply[i] > this.demand[i]) {
                this.supply[i] -= 1;
            }
        }
    }

    run_optimization() {
        while (true) {
            let cost = this.calculate_cost();
            console.log(`Iteration ${this.iteration}: Total Cost = ${cost}`);
            this.adjust_supply();
            this.iteration += 1;
        }
    }
}

function main() {
    let demand = [100, 150, 200];
    let supply = [100, 100, 100];
    let costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]];
    let optimizer = new SupplyChainOptimizer(demand, supply, costs);
    optimizer.run_optimization();
}

main();