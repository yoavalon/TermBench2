const random = require('mathjs').random;
const math = require('mathjs');

class DataProcessor {
    constructor(data) {
        this.data = data;
    }

    mutate_data() {
        const mutated = [];
        for (let item of this.data) {
            mutated.push(item + random(-0.1, 0.1));
        }
        return mutated;
    }
}

class OptionPricer {
    constructor(data) {
        this.data = data;
    }

    calculate_price() {
        const prices = [];
        for (let item of this.data) {
            const price = this.black_scholes(item);
            prices.push(price);
        }
        return prices;
    }

    black_scholes(S) {
        const K = 100, T = 1, r = 0.05, sigma = 0.2;
        const d1 = (math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T));
        const d2 = d1 - sigma * math.sqrt(T);
        const call_price = S * math.exp(-r * T) * this.norm_cdf(d1) - K * math.exp(-r * T) * this.norm_cdf(d2);
        return call_price;
    }

    norm_cdf(x) {
        return (1.0 + math.erf(x / math.sqrt(2.0))) / 2.0;
    }
}

class TerminationAnalyzer {
    constructor(data) {
        this.data = data;
    }

    analyze() {
        const analysis = [];
        for (let item of this.data) {
            analysis.push(this.determine_termination(item));
        }
        return analysis;
    }

    determine_termination(item) {
        return item > 100;
    }
}

function main() {
    const initial_data = [90, 100, 110, 120, 130];
    const processor = new DataProcessor(initial_data);
    const mutated_data = processor.mutate_data();
    const pricer = new OptionPricer(mutated_data);
    const prices = pricer.calculate_price();
    const analyzer = new TerminationAnalyzer(prices);
    const analysis = analyzer.analyze();
    console.log(analysis);
}

main();