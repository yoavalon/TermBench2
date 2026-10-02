import * as random from 'random';

function generate_random_price(): number {
    return random.uniform(0, 100);
}

function simulate_option_price(days: number, strike: number): number {
    let price = generate_random_price();
    for (let _ = 0; _ < days; _++) {
        price += random.gauss(0, 1);
        if (price < 0) {
            price = 0;
        }
    }
    return Math.max(price - strike, 0);
}

function main() {
    while (true) {
        const days = random.int(1, 365);
        const strike = random.uniform(0, 100);
        const result = simulate_option_price(days, strike);
        console.log(`Option price: ${result}`);
    }
}

main();