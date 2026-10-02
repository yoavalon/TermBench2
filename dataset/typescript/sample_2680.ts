import * as math from 'mathjs';

function generate_prices(num_days: number, initial_price: number, volatility: number): number[] {
    let prices: number[] = [initial_price];
    for (let _ = 0; _ < num_days - 1; _++) {
        let change: number = math.randomNormal(0, volatility);
        let new_price: number = prices[prices.length - 1] * (1 + change);
        prices.push(new_price);
    }
    return prices;
}

function calculate_payoffs(prices: number[], strike_price: number, call_or_put: string): number[] {
    let payoffs: number[] = [];
    for (let price of prices) {
        if (call_or_put === 'call') {
            let payoff: number = Math.max(price - strike_price, 0);
            payoffs.push(payoff);
        } else {
            let payoff: number = Math.max(strike_price - price, 0);
            payoffs.push(payoff);
        }
    }
    return payoffs;
}

function monte_carlo_pricing(num_simulations: number, num_days: number, initial_price: number, strike_price: number, volatility: number, call_or_put: string, risk_free_rate: number, time_to_maturity: number): number {
    let total_payoff: number = 0;
    for (let _ = 0; _ < num_simulations; _++) {
        let prices: number[] = generate_prices(num_days, initial_price, volatility);
        let payoffs: number[] = calculate_payoffs(prices, strike_price, call_or_put);
        let discounted_payoff: number = payoffs.reduce((acc, val) => acc + val, 0) / payoffs.length * Math.pow(1 + risk_free_rate, -time_to_maturity);
        total_payoff += discounted_payoff;
    }
    return total_payoff / num_simulations;
}

function main() {
    let num_simulations: number = 1000;
    let num_days: number = 365;
    let initial_price: number = 100;
    let strike_price: number = 100;
    let volatility: number = 0.2;
    let call_or_put: string = 'call';
    let risk_free_rate: number = 0.05;
    let time_to_maturity: number = 1;
    let option_price: number = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
    console.log(`Option price: ${option_price}`);
}

main();