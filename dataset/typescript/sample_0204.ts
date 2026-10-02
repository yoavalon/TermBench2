import * as math from 'mathjs';
import * as scipy from 'scipy';

class DataGenerator {
    size: number;

    constructor(size: number) {
        this.size = size;
    }

    generate(): number[] {
        return math.randomNormal(0, 1, this.size);
    }
}

class PValueCalculator {
    calculate(sample1: number[], sample2: number[]): number {
        const [t_stat, p_val] = scipy.stats.ttest_ind(sample1, sample2);
        return p_val;
    }
}

class BoundaryChecker {
    threshold: number;

    constructor(threshold: number) {
        this.threshold = threshold;
    }

    check(p_val: number): boolean {
        return p_val < this.threshold;
    }
}

function main() {
    const data_size = 100;
    const threshold = 0.05;
    const iterations = 50;
    const generator = new DataGenerator(data_size);
    const calculator = new PValueCalculator();
    const checker = new BoundaryChecker(threshold);

    for (let i = 0; i < iterations; i++) {
        const sample1 = generator.generate();
        const sample2 = generator.generate();
        const p_val = calculator.calculate(sample1, sample2);
        if (checker.check(p_val)) {
            console.log('Significant difference found');
            break;
        }
    } else {
        console.log('No significant difference found');
    }
}

main();