import * as math from 'mathjs';
import * as random from 'random';

class OptionPricer {
    S0: number[];
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;

    constructor(S0: number[], K: number, T: number, r: number, sigma: number, N: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_paths(): number[][] {
        const dt = this.T / this.N;
        const paths: number[][] = Array.from({ length: this.N + 1 }, () => Array(this.S0.length).fill(0));
        paths[0] = [...this.S0];
        for (let i = 1; i <= this.N; i++) {
            const z = this.S0.map(() => random.normal(0, 1));
            paths[i] = paths[i - 1].map((s, j) => s * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * z[j]));
        }
        return paths;
    }

    calculate_payoff(paths: number[][]): number[] {
        return paths[paths.length - 1].map(s => math.max(s - this.K, 0));
    }
}

class MonteCarloEngine {
    pricer: OptionPricer;
    num_simulations: number;

    constructor(pricer: OptionPricer, num_simulations: number) {
        this.pricer = pricer;
        this.num_simulations = num_simulations;
    }

    run(): number {
        const payoffs = Array(this.num_simulations).fill(0);
        for (let i = 0; i < this.num_simulations; i++) {
            const paths = this.pricer.simulate_paths();
            payoffs[i] = this.pricer.calculate_payoff(paths).reduce((a, b) => a + b, 0) / this.pricer.S0.length;
        }
        const price = math.exp(-this.pricer.r * this.pricer.T) * payoffs.reduce((a, b) => a + b, 0) / this.num_simulations;
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