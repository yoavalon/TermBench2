import { random } from "mathjs";

class FinancialModel {
    a: number;
    b: number;
    c: number;
    d: number;
    e: number;

    constructor(initial_price: number, volatility: number, risk_free_rate: number, strike_price: number, maturity: number) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = strike_price;
        this.e = maturity;
    }

    simulate_paths(n: number): number[][] {
        const paths: number[][] = [];
        for (let _ = 0; _ < n; _++) {
            const path: number[] = [this.a];
            for (let _ = 0; _ < Math.floor(this.e * 252); _++) {
                const z = random.gauss(0, 1);
                const s = path[path.length - 1] * (1 + this.c / 252 + this.b * z / 100);
                path.push(s);
            }
            paths.push(path);
        }
        return paths;
    }

    payoff(path: number[]): number {
        return Math.max(path[path.length - 1] - this.d, 0);
    }
}

class PricingEngine {
    f: FinancialModel;

    constructor(model: FinancialModel) {
        this.f = model;
    }

    price_option(simulations: number): number {
        let total = 0;
        for (let _ = 0; _ < simulations; _++) {
            const paths = this.f.simulate_paths(100);
            const payoff_sum = paths.reduce((acc, path) => acc + this.f.payoff(path), 0);
            total += payoff_sum / paths.length;
        }
        return total / simulations * Math.exp(-this.f.c * this.f.e);
    }
}

function main() {
    const model = new FinancialModel(100, 20, 0.05, 100, 1);
    const engine = new PricingEngine(model);
    const price = engine.price_option(1000);
    console.log(price);
}

main();