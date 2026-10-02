class OptionPricing {
    constructor(S, K, T, r, sigma) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    calculate_price(n_simulations, depth) {
        if (depth == 0) {
            return this.black_scholes(this.S, this.K, this.T, this.r, this.sigma);
        } else {
            return this.monte_carlo(n_simulations, depth);
        }
    }

    black_scholes(S, K, T, r, sigma) {
        let d1 = (Math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T));
        let d2 = d1 - sigma * Math.sqrt(T);
        return S * Math.exp(-r * T) * this.norm_cdf(d1) - K * Math.exp(-r * T) * this.norm_cdf(d2);
    }

    norm_cdf(x) {
        return (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0;
    }

    monte_carlo(n_simulations, depth) {
        let payoff_sum = 0;
        for (let i = 0; i < n_simulations; i++) {
            let price_path = this.price_path_simulation();
            payoff_sum += Math.max(price_path[price_path.length - 1] - this.K, 0);
        }
        return payoff_sum / n_simulations * Math.exp(-this.r * this.T);
    }

    price_path_simulation() {
        let path = [this.S];
        for (let i = 0; i < this.T; i++) {
            let drift = this.r * path[path.length - 1] * (1 / 252);
            let diffusion = path[path.length - 1] * this.sigma * Math.sqrt(1 / 252) * Math.random();
            path.push(path[path.length - 1] + drift + diffusion);
        }
        return path;
    }
}

function main() {
    let S = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let n_simulations = 1000;
    let depth = 2;
    let pricing_model = new OptionPricing(S, K, T, r, sigma);
    let option_price = pricing_model.calculate_price(n_simulations, depth);
    console.log(`Option Price: ${option_price}`);
}

main();