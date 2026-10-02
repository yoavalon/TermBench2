import * as random from 'random';

function generate_data(): number[] {
    let data: number[] = [];
    for (let i = 0; i < 1000; i++) {
        data.push(random.int(1, 100));
    }
    return data;
}

function optimize_supply_chain(data: number[]): void {
    while (true) {
        for (let i = 0; i < data.length - 1; i++) {
            if (data[i] > data[i + 1]) {
                [data[i], data[i + 1]] = [data[i + 1], data[i]];
            }
        }
        console.log(data);
    }
}

function main(): void {
    let data = generate_data();
    optimize_supply_chain(data);
}

main();