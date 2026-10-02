import * as math from 'mathjs';

class FinancialModel {
    s0: number;
    k: number;
    t: number;
    r: number;
    sigma: number;
    n_simulations: number;

    constructor(s0: number, k: number, t: number, r: number, sigma: number, n_simulations: number) {
        this.s0 = s0;
        this.k = k;
        this.t = t;
        this.r = r;
        this.sigma = sigma;
        this.n_simulations = n_simulations;
    }

    simulate_paths(): number[][] {
        const dt = this.t / 365.0;
        const paths: number[][] = Array.from({ length: this.n_simulations }, () => Array(365).fill(0));
        paths.forEach(path => path[0] = this.s0);
        for (let i = 1; i < 365; i++) {
            const z = Array.from({ length: this.n_simulations }, () => math.randomNormal(0, 1));
            paths.forEach((path, j) => {
                path[i] = path[i - 1] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * z[j]);
            });
        }
        return paths;
    }

    calculate_payoff(paths: number[][]): number[] {
        const payoff = paths.map(path => math.max(path[path.length - 1] - this.k, 0));
        return payoff;
    }
}

class OptionPricer {
    model: FinancialModel;

    constructor(model: FinancialModel) {
        this.model = model;
    }

    price_option(): number {
        const paths = this.model.simulate_paths();
        const payoff = this.model.calculate_payoff(paths);
        const option_price = math.exp(-this.model.r * this.model.t) * math.mean(payoff);
        return option_price;
    }
}

function main() {
    const s0 = 100;
    const k = 100;
    const t = 1;
    const r = 0.05;
    const sigma = 0.2;
    const n_simulations = 10000;
    const model = new FinancialModel(s0, k, t, r, sigma, n_simulations);
    const pricer = new OptionPricer(model);
    const price = pricer.price_option();
    console.log(price);
}

main();