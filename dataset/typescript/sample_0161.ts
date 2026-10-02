import * as random from 'random';

function simulate_stock_price(steps: number, initial_price: number, drift: number, volatility: number): number {
    let price = initial_price;
    for (let _ = 0; _ < steps; _++) {
        price += price * (drift + volatility * random.gauss(0, 1));
    }
    return price;
}

function price_option(pricing_function: (steps: number, initial_price: number, drift: number, volatility: number) => number, initial_price: number, strike_price: number, steps: number, drift: number, volatility: number, simulations: number): number {
    let total = 0;
    for (let _ = 0; _ < simulations; _++) {
        let final_price = pricing_function(steps, initial_price, drift, volatility);
        let payoff = Math.max(final_price - strike_price, 0);
        total += payoff;
    }
    return total / simulations;
}

function main(): void {
    let initial_price = 100;
    let strike_price = 100;
    let steps = 100;
    let drift = 0.0001;
    let volatility = 0.01;
    let simulations = 10000;
    let option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
    console.log(`Option Price: ${option_price}`);
}

main();