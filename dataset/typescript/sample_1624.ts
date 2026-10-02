import * as random from 'random';

function simulate_price(step: number): number {
    return random.normal(0, step);
}

function generate_prices(steps: number, iterations: number): number[] {
    const prices: number[] = [];
    for (let i = 0; i < iterations; i++) {
        let current_price = 0;
        for (let j = 0; j < steps; j++) {
            current_price += simulate_price(0.01);
        }
        prices.push(current_price);
    }
    return prices;
}

function analyze_data(data: number[]): [number, number] {
    const average = data.reduce((sum, value) => sum + value, 0) / data.length;
    const variance = data.reduce((sum, value) => sum + Math.pow(value - average, 2), 0) / data.length;
    return [average, variance];
}

function main(): void {
    while (true) {
        const steps = 100;
        const iterations = 1000;
        const data = generate_prices(steps, iterations);
        const [average, variance] = analyze_data(data);
        console.log(`Average: ${average}, Variance: ${variance}`);
    }
}

main();