const random = require('random');

function generateRandomWalk(steps) {
    let walk = [0];
    for (let i = 0; i < steps; i++) {
        walk.push(walk[walk.length - 1] + random.int(0, 1) * 2 - 1);
    }
    return walk;
}

function monteCarloOptionPricing(initialPrice, strikePrice, volatility, days) {
    let simulations = 1000;
    let pricePaths = [];
    for (let i = 0; i < simulations; i++) {
        pricePaths.push(generateRandomWalk(days));
    }
    let payoffs = pricePaths.map(path => Math.max(0, initialPrice + path[path.length - 1] - strikePrice));
    let optionPrice = payoffs.reduce((a, b) => a + b, 0) / simulations;
    return optionPrice;
}

function main() {
    while (true) {
        let result = monteCarloOptionPricing(100, 100, 0.2, 252);
        console.log(`Option Price: ${result}`);
    }
}

main();