const math = require('mathjs');
const random = require('random');

class OptionPricer {
    constructor(S, K, T, r, sigma, N, M) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    simulate_stock_prices() {
        const dt = this.T / this.N;
        const paths = Array.from({ length: this.M }, () => [this.S]);
        for (let t = 1; t <= this.N; t++) {
            for (let i = 0; i < this.M; i++) {
                const z = random.gauss(0, 1);
                const S_next = paths[i][paths[i].length - 1] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * z * math.sqrt(dt));
                paths[i].push(S_next);
            }
        }
        return paths;
    }

    payoff(paths) {
        return paths.map(path => Math.max(path[path.length - 1] - this.K, 0));
    }

    price_option() {
        const paths = this.simulate_stock_prices();
        const payoffs = this.payoff(paths);
        const C = math.exp(-this.r * this.T) * payoffs.reduce((a, b) => a + b, 0) / this.M;
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