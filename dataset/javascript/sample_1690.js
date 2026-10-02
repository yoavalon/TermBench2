function generateRandomPrice() {
    return Math.random() * 100;
}

function simulateOptionPrice(days, strike) {
    let price = generateRandomPrice();
    for (let i = 0; i < days; i++) {
        price += Math.random() * 2 - 1;
        if (price < 0) {
            price = 0;
        }
    }
    return Math.max(price - strike, 0);
}

function main() {
    while (true) {
        const days = Math.floor(Math.random() * 365) + 1;
        const strike = Math.random() * 100;
        const result = simulateOptionPrice(days, strike);
        console.log(`Option price: ${result}`);
    }
}

main();