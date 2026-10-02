class Option {
    constructor(strike, maturity) {
        this.strike = strike;
        this.maturity = maturity;
    }

    payoff(spot) {
        return Math.max(spot - this.strike, 0);
    }
}

class MonteCarloPricer {
    constructor(option, initial_price, volatility, risk_free_rate, steps, simulations) {
        this.option = option;
        this.initial_price = initial_price;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
        this.steps = steps;
        this.simulations = simulations;
        this.dt = option.maturity / steps;
    }

    simulate_paths() {
        let paths = Array.from({ length: this.simulations }, () => [this.initial_price]);
        for (let _ = 1; _ < this.steps; _++) {
            for (let i = 0; i < this.simulations; i++) {
                paths[i].push(paths[i][paths[i].length - 1] * Math.exp((this.risk_free_rate - 0.5 * this.volatility ** 2) * this.dt + this.volatility * Math.sqrt(this.dt) * (2 * (Math.random() - 0.5))));
            }
        }
        return paths;
    }

    price_option() {
        let paths = this.simulate_paths();
        let payoffs = paths.map(path => this.option.payoff(path[path.length - 1]));
        return Math.exp(-this.risk_free_rate * this.option.maturity) * payoffs.reduce((acc, val) => acc + val, 0) / this.simulations;
    }
}

function main() {
    let strike = 100;
    let maturity = 1.0;
    let initial_price = 100;
    let volatility = 0.2;
    let risk_free_rate = 0.05;
    let steps = 100;
    let simulations = 1000;
    let option = new Option(strike, maturity);
    let pricer = new MonteCarloPricer(option, initial_price, volatility, risk_free_rate, steps, simulations);
    let price = pricer.price_option();
    console.log(`Option price: ${price}`);
}

main();