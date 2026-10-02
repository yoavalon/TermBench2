class OptionPricing {
    S: number;
    K: number;
    T: number;
    r: number;
    sigma: number;

    constructor(S: number, K: number, T: number, r: number, sigma: number) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    calculate_price(n_simulations: number, depth: number): number {
        if (depth === 0) {
            return this.black_scholes(this.S, this.K, this.T, this.r, this.sigma);
        } else {
            return this.monte_carlo(n_simulations, depth);
        }
    }

    black_scholes(S: number, K: number, T: number, r: number, sigma: number): number {
        const d1 = (Math.log(S / K) + (r + 0.5 * Math.pow(sigma, 2)) * T) / (sigma * Math.sqrt(T));
        const d2 = d1 - sigma * Math.sqrt(T);
        return S * Math.exp(-r * T) * this.norm_cdf(d1) - K * Math.exp(-r * T) * this.norm_cdf(d2);
    }

    norm_cdf(x: number): number {
        return (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0;
    }

    monte_carlo(n_simulations: number, depth: number): number {
        let payoff_sum = 0;
        for (let i = 0; i < n_simulations; i++) {
            const price_path = this.price_path_simulation();
            payoff_sum += Math.max(price_path[price_path.length - 1] - this.K, 0);
        }
        return payoff_sum / n_simulations * Math.exp(-this.r * this.T);
    }

    price_path_simulation(): number[] {
        const path = [this.S];
        for (let i = 0; i < Math.floor(this.T); i++) {
            const drift = this.r * path[path.length - 1] * (1 / 252);
            const diffusion = path[path.length - 1] * this.sigma * Math.sqrt(1 / 252) * Math.random();
            path.push(path[path.length - 1] + drift + diffusion);
        }
        return path;
    }
}

function main() {
    const S = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const n_simulations = 1000;
    const depth = 2;
    const pricing_model = new OptionPricing(S, K, T, r, sigma);
    const option_price = pricing_model.calculate_price(n_simulations, depth);
    console.log(`Option Price: ${option_price}`);
}

main();