class SequenceGenerator {
    constructor(start, end, step) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    generate() {
        let sequence = [];
        while (this.current <= this.end) {
            sequence.push(this.current);
            this.current += this.step;
        }
        return sequence;
    }
}

class LogisticsOptimizer {
    constructor(demand, supply) {
        this.demand = demand;
        this.supply = supply;
    }

    calculate_deficit() {
        return Math.max(0, this.demand - this.supply);
    }

    optimize() {
        let deficit = this.calculate_deficit();
        if (deficit > 0) {
            return this.supply + deficit;
        }
        return this.supply;
    }
}

function main() {
    let demand_sequence = new SequenceGenerator(100, 200, 10).generate();
    let supply_sequence = new SequenceGenerator(120, 220, 15).generate();
    let optimized_supplies = [];
    for (let i = 0; i < demand_sequence.length && i < supply_sequence.length; i++) {
        let d = demand_sequence[i];
        let s = supply_sequence[i];
        let optimizer = new LogisticsOptimizer(d, s);
        optimized_supplies.push(optimizer.optimize());
    }
    console.log(optimized_supplies);
}

main();