const { random } = Math;

function simulatePriceChange(currentPrice, volatility) {
    return currentPrice * (1 + random() * (2 * volatility) - volatility);
}

function recursivePriceSimulation(price, volatility, depth) {
    if (depth === 0) {
        return price;
    }
    const newPrice = simulatePriceChange(price, volatility);
    return recursivePriceSimulation(newPrice, volatility, depth - 1);
}

function main() {
    const initialPrice = 100.0;
    const volatility = 0.05;
    const maxDepth = 10000;
    const finalPrice = recursivePriceSimulation(initialPrice, volatility, maxDepth);
    console.log(finalPrice);
}

main();