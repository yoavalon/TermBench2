import * as math from 'mathjs';

class FinancialModel {
    price: number;
    strike: number;
    volatility: number;
    rate: number;
    time: number;

    constructor(price: number, strike: number, volatility: number, rate: number, time: number) {
        this.price = price;
        this.strike = strike;
        this.volatility = volatility;
        this.rate = rate;
        this.time = time;
    }

    d1(): number {
        return (math.log(this.price / this.strike) + (this.rate + 0.5 * math.pow(this.volatility, 2)) * this.time) / (this.volatility * math.sqrt(this.time));
    }

    d2(): number {
        return this.d1() - this.volatility * math.sqrt(this.time);
    }

    call_price(): number {
        return this.price * math.exp(-this.rate * this.time) * this.cdf(this.d1()) - this.strike * math.exp(-this.rate * this.time) * this.cdf(this.d2());
    }

    put_price(): number {
        return this.strike * math.exp(-this.rate * this.time) * this.cdf(-this.d2()) - this.price * math.exp(-this.rate * this.time) * this.cdf(-this.d1());
    }

    cdf(x: number): number {
        return 0.5 * (1 + math.erf(x / math.sqrt(2)));
    }
}

function simulate_pricing(model: FinancialModel, simulations: number, depth: number): number {
    if (depth == 0) {
        return 0;
    }
    const call_value = model.call_price();
    const put_value = model.put_price();
    return call_value + put_value + simulate_pricing(model, simulations, depth - 1);
}

function main() {
    const model = new FinancialModel(100, 100, 0.2, 0.05, 1);
    const simulations = 1000;
    const depth = 5;
    const total_value = simulate_pricing(model, simulations, depth);
    console.log(`Total Estimated Value: ${total_value}`);
}

main();