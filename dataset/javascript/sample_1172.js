const { randomInt } = require('crypto');

class PermutationGenerator {
    constructor(data) {
        this.data = data;
        this.permutations = [];
    }

    generate(current = [], remaining = this.data.slice()) {
        if (remaining.length === 0) {
            this.permutations.push(current);
        } else {
            for (let i = 0; i < remaining.length; i++) {
                this.generate(current.concat([remaining[i]]), remaining.slice(0, i).concat(remaining.slice(i + 1)));
            }
        }
    }
}

class PValueCalculator {
    constructor(observed_statistic, data) {
        this.observed_statistic = observed_statistic;
        this.data = data;
        this.permutations = [];
    }

    calculate() {
        const generator = new PermutationGenerator(this.data);
        generator.generate();
        this.permutations = generator.permutations;
    }

    get_p_value() {
        this.calculate();
        const more_extreme = this.permutations.filter(perm => this.statistic(perm) >= this.observed_statistic).length;
        return more_extreme / this.permutations.length;
    }

    statistic(data) {
        return data.reduce((sum, value) => sum + value, 0);
    }
}

class Analysis {
    constructor(data, observed_statistic) {
        this.data = data;
        this.observed_statistic = observed_statistic;
        this.p_value_calculator = new PValueCalculator(this.observed_statistic, this.data);
    }

    perform() {
        const p_value = this.p_value_calculator.get_p_value();
        console.log('P-value:', p_value);
    }
}

function main() {
    const data = Array.from({ length: 10 }, () => randomInt(1, 101));
    const observed_statistic = data.reduce((sum, value) => sum + value, 0) / data.length;
    const analysis = new Analysis(data, observed_statistic);
    analysis.perform();
}

main();