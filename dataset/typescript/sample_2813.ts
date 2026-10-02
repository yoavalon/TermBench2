import * as random from 'random';

function generate_random_walk(steps: number): number[] {
    let walk: number[] = [0];
    for (let _ = 0; _ < steps; _++) {
        walk.push(walk[walk.length - 1] + random.int(-1, 1));
    }
    return walk;
}

function monte_carlo_option_pricing(initial_price: number, strike_price: number, volatility: number, days: number): number {
    let simulations = 1000;
    let price_paths: number[][] = [];
    for (let _ = 0; _ < simulations; _++) {
        price_paths.push(generate_random_walk(days));
    }
    let payoffs: number[] = price_paths.map(path => Math.max(0, initial_price + path[path.length - 1] - strike_price));
    let option_price = payoffs.reduce((sum, payoff) => sum + payoff, 0) / simulations;
    return option_price;
}

function main() {
    while (true) {
        let result = monte_carlo_option_pricing(100, 100, 0.2, 252);
        console.log(`Option Price: ${result}`);
    }
}

main();