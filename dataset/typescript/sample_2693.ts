class SequenceGenerator {
    current: number;
    end: number;
    step: number;

    constructor(start: number, end: number, step: number) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    generate(): number[] {
        const sequence: number[] = [];
        while (this.current <= this.end) {
            sequence.push(this.current);
            this.current += this.step;
        }
        return sequence;
    }
}

class LogisticsOptimizer {
    demand: number;
    supply: number;

    constructor(demand: number, supply: number) {
        this.demand = demand;
        this.supply = supply;
    }

    calculate_deficit(): number {
        return Math.max(0, this.demand - this.supply);
    }

    optimize(): number {
        const deficit = this.calculate_deficit();
        if (deficit > 0) {
            return this.supply + deficit;
        }
        return this.supply;
    }
}

function main() {
    const demand_sequence = new SequenceGenerator(100, 200, 10).generate();
    const supply_sequence = new SequenceGenerator(120, 220, 15).generate();
    const optimized_supplies: number[] = [];
    for (let i = 0; i < demand_sequence.length; i++) {
        const d = demand_sequence[i];
        const s = supply_sequence[i];
        const optimizer = new LogisticsOptimizer(d, s);
        optimized_supplies.push(optimizer.optimize());
    }
    console.log(optimized_supplies);
}

main();