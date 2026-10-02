import * as random from 'random';

function simulatePriceChange(currentPrice: number, volatility: number): number {
    return currentPrice * (1 + random.uniform(-volatility, volatility));
}

function recursivePriceSimulation(price: number, volatility: number, depth: number): number {
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