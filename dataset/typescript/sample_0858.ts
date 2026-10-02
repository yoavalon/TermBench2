import * as math from 'mathjs';
import * as random from 'random';

class MonteCarlo {
    iterations: number;
    option_type: string;
    strike: number;
    underlying: number;
    sigma: number;
    r: number;
    t: number;

    constructor(iterations: number, option_type: string, strike: number, underlying: number, sigma: number, r: number, t: number) {
        this.iterations = iterations;
        this.option_type = option_type;
        this.strike = strike;
        this.underlying = underlying;
        this.sigma = sigma;
        this.r = r;
        this.t = t;
    }

    price(): number {
        let total = 0;
        for (let i = 0; i < this.iterations; i++) {
            let price = this.underlying * math.exp(this.r * this.t + this.sigma * math.sqrt(this.t) * random.gauss(0, 1));
            let payoff = this.payoff(price);
            let discounted_payoff = payoff * math.exp(-this.r * this.t);
            total += discounted_payoff;
        }
        return total / this.iterations;
    }

    payoff(price: number): number {
        if (this.option_type === 'call') {
            return math.max(price - this.strike, 0);
        } else if (this.option_type === 'put') {
            return math.max(this.strike - price, 0);
        }
        return 0;
    }
}

class Option {
    type: string;
    strike: number;
    underlying: number;
    sigma: number;
    r: number;
    t: number;

    constructor(type: string, strike: number, underlying: number, sigma: number, r: number, t: number) {
        this.type = type;
        this.strike = strike;
        this.underlying = underlying;
        this.sigma = sigma;
        this.r = r;
        this.t = t;
    }

    evaluate(): number {
        let model = new MonteCarlo(10000, this.type, this.strike, this.underlying, this.sigma, this.r, this.t);
        return model.price();
    }
}

function main() {
    let option = new Option('call', 100, 100, 0.2, 0.05, 1);
    let result = option.evaluate();
    console.log(`Option price: ${result}`);
}

main();