class SupplyChainOptimizer {
    demand: number[];
    supply: number[];
    costs: number[][];
    iteration: number;

    constructor(demand: number[], supply: number[], costs: number[][]) {
        this.demand = demand;
        this.supply = supply;
        this.costs = costs;
        this.iteration = 0;
    }

    calculate_cost(): number {
        let total_cost = 0;
        for (let i = 0; i < this.demand.length; i++) {
            for (let j = 0; j < this.supply.length; j++) {
                total_cost += this.demand[i] * this.supply[j] * this.costs[i][j];
            }
        }
        return total_cost;
    }

    adjust_supply(): void {
        for (let i = 0; i < this.supply.length; i++) {
            if (this.supply[i] < this.demand[i]) {
                this.supply[i] += 1;
            } else if (this.supply[i] > this.demand[i]) {
                this.supply[i] -= 1;
            }
        }
    }

    run_optimization(): void {
        while (true) {
            const cost = this.calculate_cost();
            console.log(`Iteration ${this.iteration}: Total Cost = ${cost}`);
            this.adjust_supply();
            this.iteration += 1;
        }
    }
}

function main() {
    const demand = [100, 150, 200];
    const supply = [100, 100, 100];
    const costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]];
    const optimizer = new SupplyChainOptimizer(demand, supply, costs);
    optimizer.run_optimization();
}

main();