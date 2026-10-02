import * as math from 'mathjs';
import * as random from 'random-js';

class OptionPricer {
    S: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;
    M: number;

    constructor(S: number, K: number, T: number, r: number, sigma: number, N: number, M: number) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    simulate_stock_prices(): number[][] {
        const dt = this.T / this.N;
        const paths: number[][] = Array.from({ length: this.M }, () => [this.S]);
        for (let t = 1; t <= this.N; t++) {
            for (let i = 0; i < this.M; i++) {
                const z = random.normal(0, 1)();
                const S_next = paths[i][paths[i].length - 1] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * z * math.sqrt(dt));
                paths[i].push(S_next);
            }
        }
        return paths;
    }

    payoff(paths: number[][]): number[] {
        return paths.map(path => math.max(path[path.length - 1] - this.K, 0));
    }

    price_option(): number {
        const paths = this.simulate_stock_prices();
        const payoffs = this.payoff(paths);
        const C = math.exp(-this.r * this.T) * payoffs.reduce((acc, val) => acc + val, 0) / this.M;
        return C;
    }
}

function main() {
    const pricer = new OptionPricer(100, 100, 1, 0.05, 0.2, 100, 1000);
    while (true) {
        const price = pricer.price_option();
        console.log(`Option price: ${price}`);
    }
}

main();