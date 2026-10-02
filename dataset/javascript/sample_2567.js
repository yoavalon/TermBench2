const simulatePrices = (steps, simulations) => {
    const drift = 0.05;
    const volatility = 0.2;
    const initialPrice = 100;
    const dt = 1.0 / steps;
    const paths = Array.from({ length: simulations }, () => Array(steps).fill(0));
    paths.forEach(path => path[0] = initialPrice);
    for (let t = 1; t < steps; t++) {
        const z = Array.from({ length: simulations }, () => Math.random() * 2 - 1);
        paths.forEach((path, i) => {
            path[t] = path[t - 1] * Math.exp((drift - 0.5 * volatility ** 2) * dt + volatility * Math.sqrt(dt) * z[i]);
        });
    }
    return paths;
};

const optionPricing = (prices, strike, optionType = 'call') => {
    if (optionType === 'call') {
        return prices.map(price => Math.max(price - strike, 0));
    } else if (optionType === 'put') {
        return prices.map(price => Math.max(strike - price, 0));
    } else {
        return null;
    }
};

const main = () => {
    const steps = 252;
    const simulations = 10000;
    const strike = 105;
    const prices = simulatePrices(steps, simulations);
    const optionValues = optionPricing(prices.map(path => path[path.length - 1]), strike);
    console.log(optionValues.reduce((a, b) => a + b, 0) / optionValues.length);
};

main();