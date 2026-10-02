const { random } = Math;

function simulate_prices(steps, simulations) {
    const prices = new Array(steps);
    for (let i = 0; i < steps; i++) {
        prices[i] = new Array(simulations);
        for (let j = 0; j < simulations; j++) {
            prices[i][j] = random() * 0.4 + 0.05;
        }
    }
    return prices;
}

function calculate_option_value(prices, strike) {
    const final_prices = prices[prices.length - 1];
    let total = 0;
    for (let price of final_prices) {
        total += Math.max(price - strike, 0);
    }
    return total / final_prices.length;
}

function main() {
    const steps = 100;
    const simulations = 1000;
    const strike = 100;
    const prices = simulate_prices(steps, simulations);
    const value = calculate_option_value(prices, strike);
    console.log(value);
}

main();