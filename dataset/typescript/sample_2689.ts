class SupplyChainOptimization {
    demand_sequence: number[];
    production_capacity: number;
    inventory: number;
    backlog: number;
    total_cost: number;
    production_plan: number[];

    constructor(demand_sequence: number[], production_capacity: number) {
        this.demand_sequence = demand_sequence;
        this.production_capacity = production_capacity;
        this.inventory = 0;
        this.backlog = 0;
        this.total_cost = 0;
        this.production_plan = [];
    }

    calculate_production(demand: number): number {
        if (demand > this.production_capacity) {
            const production = this.production_capacity;
            this.backlog += demand - this.production_capacity;
            return production;
        } else {
            return demand;
        }
    }

    update_inventory(production: number, demand: number): void {
        this.inventory += production - demand;
    }

    update_cost(production: number, demand: number): void {
        if (this.backlog > 0) {
            this.total_cost += this.backlog * 10;
        }
        this.total_cost += production * 5;
    }

    run_optimization(): void {
        for (const demand of this.demand_sequence) {
            const production = this.calculate_production(demand);
            this.production_plan.push(production);
            this.update_inventory(production, demand);
            this.update_cost(production, demand);
        }
    }
}

function main(): void {
    const demand_sequence = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550];
    const production_capacity = 250;
    const optimizer = new SupplyChainOptimization(demand_sequence, production_capacity);
    optimizer.run_optimization();
    console.log('Total Cost:', optimizer.total_cost);
    console.log('Final Inventory:', optimizer.inventory);
    console.log('Final Backlog:', optimizer.backlog);
    console.log('Production Plan:', optimizer.production_plan);
}

main();