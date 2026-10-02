class OptionPricing {
    constructor(S0, K, T, r, sigma, N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    _simulate_paths(S0, T, r, sigma, N) {
        let dt = T / N;
        let paths = [S0];
        for (let i = 1; i <= N; i++) {
            let z = Math.random() * 2 - 1;
            let S = paths[paths.length - 1] * (1 + r * dt + sigma * z * Math.sqrt(dt));
            paths.push(S);
        }
        return paths;
    }

    _option_value(paths, K) {
        let value = 0;
        for (let S_T of paths) {
            value += Math.max(S_T - K, 0);
        }
        return value / paths.length;
    }

    price() {
        let paths = this._simulate_paths(this.S0, this.T, this.r, this.sigma, this.N);
        return this._option_value(paths, this.K);
    }
}

function main() {
    let S0 = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 1000;
    let option = new OptionPricing(S0, K, T, r, sigma, N);
    let result = option.price();
    console.log(`Option price: ${result}`);
}

main();