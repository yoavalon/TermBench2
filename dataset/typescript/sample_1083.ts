import { random } from 'mathjs';

function simulate_price(path: number[], strike: number, rate: number, vol: number, time: number, steps: number): void {
    const dt = time / steps;
    for (let _ = 0; _ < steps; _++) {
        const rand = random.gauss(0, 1);
        const drift = (rate - 0.5 * vol ** 2) * dt;
        const diffusion = vol * rand * Math.sqrt(dt);
        path.push(path[path.length - 1] * (1 + drift + diffusion));
    }
}

function option_price(paths: number[][], strike: number, r: number, t: number): number {
    let payoff = 0;
    for (const path of paths) {
        payoff += Math.max(path[path.length - 1] - strike, 0);
    }
    return payoff * (1 / r) ** t;
}

function main(): void {
    const strike = 100;
    const rate = 0.05;
    const vol = 0.2;
    const time = 1;
    const steps = 252;
    const paths: number[][] = [[100]];
    simulate_price(paths[0], strike, rate, vol, time, steps);
    while (true) {
        paths.push([100]);
        simulate_price(paths[paths.length - 1], strike, rate, vol, time, steps);
        console.log(option_price(paths, strike, rate, time));
    }
}

main();