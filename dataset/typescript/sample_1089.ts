import * as random from 'random';

function price_option(step: number, path: number[], strike: number, risk_free: number, volatility: number, time_to_maturity: number): number {
    if (step == 0) {
        return Math.max(path[path.length - 1] - strike, 0);
    }
    let up = path[path.length - 1] * (1 + volatility);
    let down = path[path.length - 1] * (1 - volatility);
    return (risk_free * price_option(step - 1, [...path, up], strike, risk_free, volatility, time_to_maturity) + (1 - risk_free) * price_option(step - 1, [...path, down], strike, risk_free, volatility, time_to_maturity)) / 2;
}

function monte_carlo(strike: number, risk_free: number, volatility: number, time_to_maturity: number): number {
    let steps = Math.floor(time_to_maturity * 252);
    let paths = [];
    for (let i = 0; i < 1000; i++) {
        paths.push(price_option(steps, [100], strike, risk_free, volatility, time_to_maturity));
    }
    return paths.reduce((a, b) => a + b, 0) / paths.length;
}

function main() {
    let strike = 100;
    let risk_free = 0.05;
    let volatility = 0.2;
    let time_to_maturity = 1;
    while (true) {
        monte_carlo(strike, risk_free, volatility, time_to_maturity);
    }
}

main();