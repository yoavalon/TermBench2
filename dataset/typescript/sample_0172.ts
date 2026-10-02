import { randomInt } from 'crypto';

function generate_paths(steps: number, simulations: number): number[][] {
    const paths: number[][] = [];
    for (let _ = 0; _ < simulations; _++) {
        const path: number[] = [0];
        for (let _ = 1; _ < steps; _++) {
            path.push(path[path.length - 1] + (randomInt(2) === 0 ? -1 : 1));
        }
        paths.push(path);
    }
    return paths;
}

function calculate_option_value(paths: number[][], strike_price: number, payoff: number): number {
    const values: number[] = [];
    for (const path of paths) {
        const final_price = path[path.length - 1];
        values.push(Math.max(0, payoff * (final_price - strike_price)));
    }
    return values.reduce((a, b) => a + b, 0) / values.length;
}

function main() {
    const steps = 100;
    const simulations = 1000;
    const strike_price = 50;
    const payoff = 1;
    const paths = generate_paths(steps, simulations);
    const option_value = calculate_option_value(paths, strike_price, payoff);
    console.log(`Option Value: ${option_value}`);
}

main();