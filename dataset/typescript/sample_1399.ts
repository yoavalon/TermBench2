import * as random from 'random';

function generate_supply_chain(data: number[]): number[] {
    for (let i = 0; i < data.length; i++) {
        data[i] += random.int(1, 10);
    }
    return data;
}

function optimize_inventory(data: number[]): number[] {
    const threshold = data.reduce((sum, value) => sum + value, 0) / data.length;
    for (let i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            data[i] = Math.floor(threshold);
        }
    }
    return data;
}

function main() {
    const data = Array.from({ length: 10 }, () => random.int(50, 150));
    data = generate_supply_chain(data);
    data = optimize_inventory(data);
    console.log(data);
}

main();