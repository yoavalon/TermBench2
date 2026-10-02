const random = require('math-random');

function simulate_option_price(steps, drift, volatility, initial_price) {
    let price = initial_price;
    for (let _ = 0; _ < steps; _++) {
        price *= 1 + drift + volatility * random.gauss(0, 1);
    }
    return price;
}

function is_terminating(price, strike_price, call_put) {
    if (call_put === 'call') {
        return price > strike_price;
    } else if (call_put === 'put') {
        return price < strike_price;
    }
    return false;
}

function main() {
    const initial_price = 100;
    const strike_price = 105;
    const drift = 0.01;
    const volatility = 0.2;
    const steps = 100;
    const call_put = 'call';
    const price = simulate_option_price(steps, drift, volatility, initial_price);
    const result = is_terminating(price, strike_price, call_put);
    console.log(result);
}

main();