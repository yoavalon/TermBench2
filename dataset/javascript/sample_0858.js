const math = require('mathjs');
const random = require('random');

class MonteCarlo {
    constructor(iterations, option_type, strike, underlying, sigma, r, t) {
        this.iterations = iterations;
        this.option_type = option_type;
        this.strike = strike;
        this.underlying = underlying;
        this.sigma = sigma;
        this.r = r;
        this.t = t;
    }

    price() {
        let total = 0;
        for (let _ = 0; _ < this.iterations; _++) {
            let price = this.underlying * math.exp(this.r * this.t + this.sigma * math.sqrt(this.t) * random.gauss(0, 1));
            let payoff = this.payoff(price);
            let discounted_payoff = payoff * math.exp(-this.r * this.t);
            total += discounted_payoff;
        }
        return total / this.iterations;
    }

    payoff(price) {
        if (this.option_type === 'call') {
            return math.max(price - this.strike, 0);
        } else if (this.option_type === 'put') {
            return math.max(this.strike - price, 0);
        }
    }
}

class Option {
    constructor(type, strike, underlying, sigma, r, t) {
        this.type = type;
        this.strike = strike;
        this.underlying = underlying;
        this.sigma = sigma;
        this.r = r;
        this.t = t;
    }

    evaluate() {
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