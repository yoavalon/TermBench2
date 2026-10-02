import { randomInt } from 'crypto';

class PermutationGenerator {
    data: number[];
    permutations: number[][];

    constructor(data: number[]) {
        this.data = data;
        this.permutations = [];
    }

    generate(current: number[] = [], remaining: number[] | null = null): void {
        if (remaining === null) {
            remaining = [...this.data];
        }
        if (remaining.length === 0) {
            this.permutations.push(current);
        } else {
            for (let i = 0; i < remaining.length; i++) {
                this.generate(current.concat(remaining[i]), remaining.slice(0, i).concat(remaining.slice(i + 1)));
            }
        }
    }
}

class PValueCalculator {
    observed_statistic: number;
    data: number[];
    permutations: number[][];

    constructor(observed_statistic: number, data: number[]) {
        this.observed_statistic = observed_statistic;
        this.data = data;
        this.permutations = [];
    }

    calculate(): void {
        const generator = new PermutationGenerator(this.data);
        generator.generate();
        this.permutations = generator.permutations;
    }

    get_p_value(): number {
        this.calculate();
        const more_extreme = this.permutations.filter(perm => this.statistic(perm) >= this.observed_statistic).length;
        return more_extreme / this.permutations.length;
    }

    statistic(data: number[]): number {
        return data.reduce((acc, val) => acc + val, 0);
    }
}

class Analysis {
    data: number[];
    observed_statistic: number;
    p_value_calculator: PValueCalculator;

    constructor(data: number[], observed_statistic: number) {
        this.data = data;
        this.observed_statistic = observed_statistic;
        this.p_value_calculator = new PValueCalculator(this.observed_statistic, this.data);
    }

    perform(): void {
        const p_value = this.p_value_calculator.get_p_value();
        console.log('P-value:', p_value);
    }
}

function main(): void {
    const data = Array.from({ length: 10 }, () => randomInt(1, 101));
    const observed_statistic = data.reduce((acc, val) => acc + val, 0) / data.length;
    const analysis = new Analysis(data, observed_statistic);
    analysis.perform();
}

main();