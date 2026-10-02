import * as random from 'mathjs';

class OptionPricing {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number, N: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    _simulate_paths(S0: number, T: number, r: number, sigma: number, N: number): number[] {
        const dt = T / N;
        const paths: number[] = [S0];
        for (let i = 1; i <= N; i++) {
            const z = random.normal(0, 1);
            const S = paths[i - 1] * (1 + r * dt + sigma * z * Math.sqrt(dt));
            paths.push(S);
        }
        return paths;
    }

    _option_value(paths: number[], K: number): number {
        let value = 0;
        for (const S_T of paths) {
            value += Math.max(S_T - K, 0);
        }
        return value / paths.length;
    }

    price(): number {
        const paths = this._simulate_paths(this.S0, this.T, this.r, this.sigma, this.N);
        return this._option_value(paths, this.K);
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 1000;
    const option = new OptionPricing(S0, K, T, r, sigma, N);
    const result = option.price();
    console.log(`Option price: ${result}`);
}

main();