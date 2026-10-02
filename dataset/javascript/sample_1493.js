const { random } = require('mathjs');

class OptionPricer {
    constructor(S0, K, T, r, sigma, N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_paths() {
        const dt = this.T / this.N;
        const paths = Array.from({ length: this.N + 1 }, () => Array(this.S0.length).fill(0));
        paths[0] = this.S0;
        for (let i = 1; i <= this.N; i++) {
            const z = this.S0.map(() => random.normal(0, 1));
            paths[i] = paths[i - 1].map((val, j) => val * Math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * Math.sqrt(dt) * z[j]));
        }
        return paths;
    }

    calculate_payoff(paths) {
        const payoff = paths[paths.length - 1].map(val => Math.max(val - this.K, 0));
        return payoff;
    }
}

class MonteCarloEngine {
    constructor(pricer, num_simulations) {
        this.pricer = pricer;
        this.num_simulations = num_simulations;
    }

    run() {
        const payoffs = Array(this.num_simulations).fill(0);
        for (let i = 0; i < this.num_simulations; i++) {
            const paths = this.pricer.simulate_paths();
            payoffs[i] = this.pricer.calculate_payoff(paths);
        }
        const price = Math.exp(-this.pricer.r * this.pricer.T) * payoffs.reduce((acc, val) => acc + val, 0) / this.num_simulations;
        return price;
    }
}

function main() {
    const S0 = [100];
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const num_simulations = 10000;
    const pricer = new OptionPricer(S0, K, T, r, sigma, N);
    const engine = new MonteCarloEngine(pricer, num_simulations);
    const option_price = engine.run();
    console.log(`Option Price: ${option_price}`);
}

main();