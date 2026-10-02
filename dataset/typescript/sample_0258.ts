class SupplyChainOptimization {
    demand: number;
    supply: number;
    cost: number;
    iteration: number;
    max_iterations: number;

    constructor(demand: number, supply: number, cost: number) {
        this.demand = demand;
        this.supply = supply;
        this.cost = cost;
        this.iteration = 0;
        this.max_iterations = 100;
    }

    calculate_shortage(): number {
        return Math.max(0, this.demand - this.supply);
    }

    adjust_supply(): number {
        const shortage = this.calculate_shortage();
        if (shortage > 0) {
            const adjustment = Math.min(shortage, this.supply * 0.1);
            this.supply += adjustment;
            return adjustment;
        }
        return 0;
    }

    update_cost(adjustment: number): void {
        if (adjustment > 0) {
            this.cost += adjustment * 0.05;
        }
    }

    run_optimization(): void {
        while (this.iteration < this.max_iterations) {
            const shortage = this.calculate_shortage();
            if (shortage === 0) {
                break;
            }
            const adjustment = this.adjust_supply();
            this.update_cost(adjustment);
            this.iteration += 1;
        }
    }
}

function main() {
    const demand = 500;
    const supply = 450;
    const cost = 1000;
    const optimizer = new SupplyChainOptimization(demand, supply, cost);
    optimizer.run_optimization();
    console.log(`Final Supply: ${optimizer.supply}, Final Cost: ${optimizer.cost}`);
}

if (require.main === module) {
    main();
}