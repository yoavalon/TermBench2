class RandomGenerator {
    seed: number;

    constructor(seed: number) {
        this.seed = seed;
    }

    generate(): number {
        this.seed = (1664525 * this.seed + 1013904223) % 4294967296;
        return this.seed / 4294967296;
    }
}

class OptionPricer {
    random_gen: RandomGenerator;
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;

    constructor(random_gen: RandomGenerator, S0: number, K: number, T: number, r: number, sigma: number, N: number) {
        this.random_gen = random_gen;
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_paths(): number[][] {
        const paths: number[][] = [];
        const dt = this.T / this.N;
        for (let _ = 0; _ < 1000; _++) {
            let S = this.S0;
            const path: number[] = [S];
            for (let _ = 0; _ < this.N; _++) {
                const Z = this.random_gen.generate();
                S += S * this.r * dt + S * this.sigma * Math.sqrt(dt) * (2 * Z - 1);
                path.push(S);
            }
            paths.push(path);
        }
        return paths;
    }

    price(): number {
        const paths = this.simulate_paths();
        let payoff_sum = 0;
        for (const path of paths) {
            const payoff = Math.max(path[path.length - 1] - this.K, 0);
            payoff_sum += payoff;
        }
        return Math.exp(-this.r * this.T) * (payoff_sum / paths.length);
    }
}

function main() {
    const seed = 12345;
    const random_gen = new RandomGenerator(seed);
    const pricer = new OptionPricer(random_gen, 100, 100, 1, 0.05, 0.2, 100);
    const option_price = pricer.price();
    console.log(`Option Price: ${option_price}`);
}

main();