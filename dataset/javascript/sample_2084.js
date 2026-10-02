const FinancialModel = class {
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
        const S = Array.from({ length: this.N }, () => Array(this.N).fill(0));
        S[0] = this.S0;
        for (let t = 1; t < this.N; t++) {
            const Z = Array.from({ length: this.N }, () => Math.random() * 2 - 1);
            S[t] = S[t - 1].map((s, i) => s * Math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * Math.sqrt(dt) * Z[i]));
        }
        return S;
    }
};

const OptionPricer = class {
    constructor(model) {
        this.model = model;
    }

    european_call() {
        const S = this.model.simulate_paths();
        const payoff = S[S.length - 1].map(s => Math.max(s - this.model.K, 0));
        const option_price = Math.exp(-this.model.r * this.model.T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
        return option_price;
    }

    european_put() {
        const S = this.model.simulate_paths();
        const payoff = S[S.length - 1].map(s => Math.max(this.model.K - s, 0));
        const option_price = Math.exp(-this.model.r * this.model.T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
        return option_price;
    }
};

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 1000;
    const model = new FinancialModel(S0, K, T, r, sigma, N);
    const pricer = new OptionPricer(model);
    const call_price = pricer.european_call();
    const put_price = pricer.european_put();
    console.log('European Call Price:', call_price);
    console.log('European Put Price:', put_price);
}

main();