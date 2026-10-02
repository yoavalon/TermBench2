class RandomNumberGenerator {
    constructor(seed = 42) {
        this.state = seed;
    }

    next() {
        this.state = (this.state * 1103515245 + 12345) % Math.pow(2, 31);
        return this.state / Math.pow(2, 31);
    }
}

class OptionPricer {
    constructor(rng, strike, maturity, volatility, risk_free_rate) {
        this.rng = rng;
        this.strike = strike;
        this.maturity = maturity;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
    }

    simulate(steps) {
        const price_paths = [];
        for (let i = 0; i < steps; i++) {
            let price = 1.0;
            for (let j = 0; j < steps; j++) {
                const drift = this.risk_free_rate - 0.5 * Math.pow(this.volatility, 2);
                const diffusion = this.volatility * this.rng.next();
                price *= 1 + drift + diffusion;
            }
            price_paths.push(price);
        }
        return price_paths;
    }

    payoff(price_paths) {
        return price_paths.map(path => Math.max(path - this.strike, 0));
    }

    price(steps) {
        const price_paths = this.simulate(steps);
        const payoff_values = this.payoff(price_paths);
        return payoff_values.reduce((acc, val) => acc + val, 0) * Math.exp(-this.risk_free_rate * this.maturity) / payoff_values.length;
    }
}

function main() {
    const rng = new RandomNumberGenerator();
    const pricer = new OptionPricer(rng, 100, 1, 0.2, 0.05);
    const option_price = pricer.price(1000);
    console.log(option_price);
}

main();