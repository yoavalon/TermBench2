import * as math from 'mathjs';
import * as random from 'random';

function random_walk(steps: number): number[] {
    let position = 0;
    let walk: number[] = [position];
    for (let i = 0; i < steps; i++) {
        let step = random.choice([-1, 1]);
        position += step;
        walk.push(position);
    }
    return walk;
}

function brownian_motion(steps: number, dt: number, initial: number = 0): number[] {
    let motion: number[] = [initial];
    let current = initial;
    for (let i = 0; i < steps; i++) {
        let drift = 0;
        let diffusion = math.sqrt(dt) * random.gauss(0, 1);
        current += drift + diffusion;
        motion.push(current);
    }
    return motion;
}

class OptionPricer {
    strike: number;
    expiry: number;

    constructor(strike: number, expiry: number) {
        this.strike = strike;
        this.expiry = expiry;
    }

    price(path: number[]): number {
        let value_at_expiry = path[path.length - 1];
        return Math.max(0, value_at_expiry - this.strike);
    }
}

function simulate_option_price(strike: number, expiry: number, steps: number, dt: number): number {
    let pricer = new OptionPricer(strike, expiry);
    let paths: number[][] = [];
    for (let i = 0; i < 1000; i++) {
        paths.push(brownian_motion(steps, dt));
    }
    let prices: number[] = paths.map(path => pricer.price(path));
    return prices.reduce((acc, val) => acc + val, 0) / prices.length;
}

function main() {
    let strike_price = 100;
    let expiry_time = 1;
    let time_steps = 100;
    let delta_t = expiry_time / time_steps;
    while (true) {
        let price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t);
        console.log(`Simulated Option Price: ${price}`);
    }
}

main();