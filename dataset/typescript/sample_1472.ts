import * as random from 'mathjs';

class FinancialModel {
    a: number;
    b: number;
    c: number;
    d: number;
    e: number;

    constructor(initial_price: number, volatility: number, risk_free_rate: number, time_steps: number, num_simulations: number) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = time_steps;
        this.e = num_simulations;
    }

    generate_paths(): number[][] {
        const paths: number[][] = [];
        for (let _ = 0; _ < this.e; _++) {
            const path: number[] = [this.a];
            for (let _ = 0; _ < this.d; _++) {
                const z = random.normal(0, 1);
                const next_price = path[path.length - 1] * Math.exp(this.c - 0.5 * this.b ** 2 + this.b * z);
                path.push(next_price);
            }
            paths.push(path);
        }
        return paths;
    }
}

class OptionPricer {
    f: FinancialModel;
    g: number;
    h: string;

    constructor(model: FinancialModel, strike_price: number, option_type: string = 'call') {
        this.f = model;
        this.g = strike_price;
        this.h = option_type;
    }

    price_option(): number {
        const paths = this.f.generate_paths();
        const payoffs: number[] = [];
        for (const path of paths) {
            if (this.h === 'call') {
                const payoff = Math.max(path[path.length - 1] - this.g, 0);
                payoffs.push(payoff);
            } else {
                const payoff = Math.max(this.g - path[path.length - 1], 0);
                payoffs.push(payoff);
            }
        }
        return payoffs.reduce((sum, payoff) => sum + payoff, 0) / this.f.e;
    }
}

function main() {
    const model = new FinancialModel(100, 0.2, 0.05, 100, 10000);
    const pricer = new OptionPricer(model, 100, 'call');
    const option_price = pricer.price_option();
    console.log(`Option Price: ${option_price}`);
}

main();