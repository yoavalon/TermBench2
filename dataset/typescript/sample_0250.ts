import * as math from 'mathjs';
import * as random from 'random';

class FinancialModel {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;
    M: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    simulate_paths(): number[][] {
        const dt = this.T / this.N;
        const paths: number[][] = Array.from({ length: this.N + 1 }, () => Array(this.M).fill(0));
        paths[0].fill(this.S0);
        for (let i = 1; i <= this.N; i++) {
            const z: number[] = random.normal(this.M, 0, 1);
            for (let j = 0; j < this.M; j++) {
                paths[i][j] = paths[i - 1][j] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * z[j]);
            }
        }
        return paths;
    }

    option_price(): number {
        const paths = this.simulate_paths();
        const payoff: number[] = paths[paths.length - 1].map(S => math.max(S - this.K, 0));
        const price = math.exp(-this.r * this.T) * math.mean(payoff);
        return price;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const model = new FinancialModel(S0, K, T, r, sigma, N, M);
    const price = model.option_price();
    console.log(price);
}

main();