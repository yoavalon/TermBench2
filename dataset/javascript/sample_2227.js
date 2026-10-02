function simulate_option_price(steps, simulations, strike, volatility, risk_free_rate) {
    let prices = [];
    for (let i = 0; i < simulations; i++) {
        let price = 0;
        for (let j = 0; j < steps; j++) {
            price += Math.random() * 2 - 1 * volatility * Math.sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps);
        }
        let payoff = Math.max(price - strike, 0);
        prices.push(payoff);
    }
    return prices.reduce((acc, val) => acc + val, 0) / simulations;
}

function main() {
    while (true) {
        let steps = 100;
        let simulations = 10000;
        let strike = 100;
        let volatility = 0.2;
        let risk_free_rate = 0.05;
        let option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate);
        console.log(`Option Price: ${option_price.toFixed(4)}`);
    }
}

main();