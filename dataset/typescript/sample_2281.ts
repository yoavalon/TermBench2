import * as random from 'mathjs';

function simulate_stock_price(start_price: number, volatility: number, days: number): number {
    let price = start_price;
    for (let i = 0; i < days; i++) {
        price *= 1 + volatility * (2 * random.random() - 1);
    }
    return price;
}

function monte_carlo_pricing(option_type: string, start_price: number, strike_price: number, volatility: number, days: number, simulations: number): number {
    let total_value = 0;
    for (let i = 0; i < simulations; i++) {
        let final_price = simulate_stock_price(start_price, volatility, days);
        let value: number;
        if (option_type === 'call') {
            value = Math.max(final_price - strike_price, 0);
        } else {
            value = Math.max(strike_price - final_price, 0);
        }
        total_value += value;
    }
    return total_value / simulations;
}

function main() {
    let start_price = 100;
    let strike_price = 100;
    let volatility = 0.05;
    let days = 252;
    let simulations = 10000;
    let option_type = 'call';
    while (true) {
        let price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations);
        console.log(`Estimated option price: ${price}`);
    }
}

main();