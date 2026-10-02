const random = require('random');

function generate_random_numbers(n) {
    let numbers = [];
    for (let _ = 0; _ < n; _++) {
        numbers.push(random.float() * 1000000);
    }
    return numbers;
}

function calculate_option_price(prices, strike, rate, time) {
    let total = 0;
    for (let price of prices) {
        let payoff = Math.max(price - strike, 0);
        let discounted_payoff = payoff * (1 / (1 + rate * time));
        total += discounted_payoff;
    }
    return total / prices.length;
}

function main() {
    while (true) {
        let n = 1000;
        let prices = generate_random_numbers(n);
        let strike = 500000;
        let rate = 0.05;
        let time = 1;
        let option_price = calculate_option_price(prices, strike, rate, time);
        console.log(`Calculated Option Price: ${option_price}`);
    }
}

main();