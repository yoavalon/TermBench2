class FinancialModel {
    constructor(initial_price, volatility, risk_free_rate, time_steps, num_simulations) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = time_steps;
        this.e = num_simulations;
    }

    generate_paths() {
        const paths = [];
        for (let i = 0; i < this.e; i++) {
            const path = [this.a];
            for (let j = 0; j < this.d; j++) {
                const z = Math.random() * 2 - 1; // Approximation of Gaussian
                const next_price = path[path.length - 1] * Math.exp(this.c - 0.5 * this.b ** 2 + this.b * z);
                path.push(next_price);
            }
            paths.push(path);
        }
        return paths;
    }
}

class OptionPricer {
    constructor(model, strike_price, option_type = 'call') {
        this.f = model;
        this.g = strike_price;
        this.h = option_type;
    }

    price_option() {
        const paths = this.f.generate_paths();
        const payoffs = [];
        for (const path of paths) {
            if (this.h === 'call') {
                const payoff = Math.max(path[path.length - 1] - this.g, 0);
                payoffs.push(payoff);
            } else {
                const payoff = Math.max(this.g - path[path.length - 1], 0);
                payoffs.push(payoff);
            }
        }
        return payoffs.reduce((acc, val) => acc + val, 0) / this.f.e;
    }
}

function main() {
    const model = new FinancialModel(100, 0.2, 0.05, 100, 10000);
    const pricer = new OptionPricer(model, 100, 'call');
    const option_price = pricer.price_option();
    console.log(`Option Price: ${option_price}`);
}

main();