const math = require('mathjs');
const random = require('mathjs').random;

function random_walk(steps) {
    let position = 0;
    let walk = [position];
    for (let i = 0; i < steps; i++) {
        let step = random.choice([-1, 1]);
        position += step;
        walk.push(position);
    }
    return walk;
}

function brownian_motion(steps, dt, initial = 0) {
    let motion = [initial];
    let current = initial;
    for (let i = 0; i < steps; i++) {
        let drift = 0;
        let diffusion = math.sqrt(dt) * random.normal(0, 1);
        current += drift + diffusion;
        motion.push(current);
    }
    return motion;
}

class OptionPricer {
    constructor(strike, expiry) {
        this.strike = strike;
        this.expiry = expiry;
    }

    price(path) {
        let value_at_expiry = path[path.length - 1];
        return Math.max(0, value_at_expiry - this.strike);
    }
}

function simulate_option_price(strike, expiry, steps, dt) {
    let pricer = new OptionPricer(strike, expiry);
    let paths = Array.from({ length: 1000 }, () => brownian_motion(steps, dt));
    let prices = paths.map(path => pricer.price(path));
    return prices.reduce((a, b) => a + b, 0) / prices.length;
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