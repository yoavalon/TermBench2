import * as math from 'mathjs';

function simulate_prices(steps: number, simulations: number): number[][] {
    const drift = 0.05;
    const volatility = 0.2;
    const initial_price = 100;
    const dt = 1.0 / steps;
    const paths = Array.from({ length: simulations }, () => Array(steps).fill(0));
    paths.forEach(path => path[0] = initial_price);
    for (let t = 1; t < steps; t++) {
        const z = Array.from({ length: simulations }, () => math.randomNormal(0, 1));
        paths.forEach((path, i) => path[t] = path[t - 1] * math.exp((drift - 0.5 * volatility ** 2) * dt + volatility * math.sqrt(dt) * z[i]));
    }
    return paths;
}

function option_pricing(prices: number[], strike: number, option_type: string = 'call'): number[] | null {
    if (option_type === 'call') {
        return prices.map(price => Math.max(price - strike, 0));
    } else if (option_type === 'put') {
        return prices.map(price => Math.max(strike - price, 0));
    } else {
        return null;
    }
}

function main() {
    const steps = 252;
    const simulations = 10000;
    const strike = 105;
    const prices = simulate_prices(steps, simulations);
    const option_values = option_pricing(prices.map(path => path[path.length - 1]), strike);
    console.log(math.mean(option_values!));
}

main();