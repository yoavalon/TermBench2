const { random } = Math;

function generate_prices(num_days, initial_price, volatility) {
    let prices = [initial_price];
    for (let _ = 0; _ < num_days - 1; _++) {
        let change = random() * 2 - 1;
        let new_price = prices[prices.length - 1] * (1 + change * volatility);
        prices.push(new_price);
    }
    return prices;
}

function calculate_payoffs(prices, strike_price, call_or_put) {
    let payoffs = [];
    for (let price of prices) {
        let payoff;
        if (call_or_put === 'call') {
            payoff = Math.max(price - strike_price, 0);
        } else {
            payoff = Math.max(strike_price - price, 0);
        }
        payoffs.push(payoff);
    }
    return payoffs;
}

function monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity) {
    let total_payoff = 0;
    for (let _ = 0; _ < num_simulations; _++) {
        let prices = generate_prices(num_days, initial_price, volatility);
        let payoffs = calculate_payoffs(prices, strike_price, call_or_put);
        let discounted_payoff = payoffs.reduce((a, b) => a + b, 0) / payoffs.length * Math.pow(1 + risk_free_rate, -time_to_maturity);
        total_payoff += discounted_payoff;
    }
    return total_payoff / num_simulations;
}

function main() {
    let num_simulations = 1000;
    let num_days = 365;
    let initial_price = 100;
    let strike_price = 100;
    let volatility = 0.2;
    let call_or_put = 'call';
    let risk_free_rate = 0.05;
    let time_to_maturity = 1;
    let option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
    console.log(`Option price: ${option_price}`);
}

main();