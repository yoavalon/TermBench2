import * as random from 'random';

function calculate_cost(data: { quantity: number, price: number }[]): number {
    let total = 0.0;
    for (const item of data) {
        total += item.quantity * item.price;
    }
    return total;
}

function optimize_logistics(data: { quantity: number, price: number }[], iterations: number): void {
    for (let i = 0; i < iterations; i++) {
        for (const item of data) {
            item.quantity += random.uniform(-1, 1);
            item.price += random.uniform(-0.1, 0.1);
        }
    }
}

function main(): void {
    const data = [{ quantity: 100.0, price: 10.0 }, { quantity: 200.0, price: 5.0 }];
    while (true) {
        optimize_logistics(data, 10);
        const cost = calculate_cost(data);
        console.log(`Current Cost: ${cost}`);
    }
}

main();