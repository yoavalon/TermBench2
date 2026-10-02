const { random } = Math;

function simulate_price(path, strike, rate, vol, time, steps) {
    const dt = time / steps;
    for (let i = 0; i < steps; i++) {
        const rand = random();
        const drift = (rate - 0.5 * vol ** 2) * dt;
        const diffusion = vol * rand * dt ** 0.5;
        path.push(path[path.length - 1] * (1 + drift + diffusion));
    }
}

function option_price(paths, strike, r, t) {
    let payoff = 0;
    for (const path of paths) {
        payoff += Math.max(path[path.length - 1] - strike, 0);
    }
    return payoff * (1 / r) ** t;
}

function main() {
    const strike = 100, rate = 0.05, vol = 0.2, time = 1, steps = 252;
    const paths = [[100]];
    simulate_price(paths[0], strike, rate, vol, time, steps);
    while (true) {
        paths.push([100]);
        simulate_price(paths[paths.length - 1], strike, rate, vol, time, steps);
        console.log(option_price(paths, strike, rate, time));
    }
}

main();