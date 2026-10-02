class SequenceGenerator {
    current: number;
    increment: number;

    constructor(start: number, increment: number) {
        this.current = start;
        this.increment = increment;
    }

    generate(count: number): number[] {
        const sequence: number[] = [];
        for (let i = 0; i < count; i++) {
            sequence.push(this.current);
            this.current += this.increment;
        }
        return sequence;
    }
}

class SupplyChainOptimizer {
    demand: number;
    supply: number;

    constructor(demand: number, supply: number) {
        this.demand = demand;
        this.supply = supply;
    }

    calculate_deficit(): number {
        const deficit = this.demand - this.supply;
        return Math.max(deficit, 0);
    }

    optimize_supply(additional_supply: number): void {
        this.supply += additional_supply;
    }
}

class SupplyChain {
    demand_sequence: number[];
    supply_sequence: number[];
    optimizer: SupplyChainOptimizer;

    constructor(demand_sequence: number[], supply_sequence: number[]) {
        this.demand_sequence = demand_sequence;
        this.supply_sequence = supply_sequence;
        this.optimizer = new SupplyChainOptimizer(0, 0);
    }

    run_optimization(): void {
        for (let i = 0; i < this.demand_sequence.length; i++) {
            const demand = this.demand_sequence[i];
            const supply = this.supply_sequence[i];
            this.optimizer.supply = supply;
            const deficit = this.optimizer.calculate_deficit();
            if (deficit > 0) {
                const additional_supply = new SequenceGenerator(deficit, 1).generate(1)[0];
                this.optimizer.optimize_supply(additional_supply);
            }
            console.log(`Demand: ${demand}, Supply: ${supply}, Deficit: ${deficit}, Adjusted Supply: ${this.optimizer.supply}`);
        }
    }
}

function main(): void {
    const demand_gen = new SequenceGenerator(100, 10);
    const demand_sequence = demand_gen.generate(10);
    const supply_gen = new SequenceGenerator(80, 5);
    const supply_sequence = supply_gen.generate(10);
    const supply_chain = new SupplyChain(demand_sequence, supply_sequence);
    supply_chain.run_optimization();
}

main();