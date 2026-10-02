const { random } = Math;

class OptionPricer {
    constructor(S, K, T, r, sigma) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    simulate_paths(num_simulations, num_steps) {
        const paths = [];
        for (let i = 0; i < num_simulations; i++) {
            const path = [this.S];
            for (let j = 0; j < num_steps - 1; j++) {
                const delta_t = this.T / num_steps;
                const drift = (this.r - 0.5 * this.sigma ** 2) * delta_t;
                const diffusion = this.sigma * random() * delta_t ** 0.5;
                const next_price = path[path.length - 1] * (1 + drift + diffusion);
                path.push(next_price);
            }
            paths.push(path);
        }
        return paths;
    }

    calculate_payoff(paths) {
        const payoffs = [];
        for (let path of paths) {
            const payoff = Math.max(path[path.length - 1] - this.K, 0);
            payoffs.push(payoff);
        }
        return payoffs;
    }

    price_option(num_simulations, num_steps) {
        const paths = this.simulate_paths(num_simulations, num_steps);
        const payoffs = this.calculate_payoff(paths);
        const option_price = payoffs.reduce((a, b) => a + b, 0) / num_simulations * (1 / this.r);
        return option_price;
    }
}

function recursive_pricer(pricer, num_simulations, num_steps) {
    const current_price = pricer.price_option(num_simulations, num_steps);
    console.log(`Current option price: ${current_price}`);
    return recursive_pricer(pricer, num_simulations, num_steps);
}

function main() {
    const S = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const pricer = new OptionPricer(S, K, T, r, sigma);
    recursive_pricer(pricer, 1000, 100);
}

main();