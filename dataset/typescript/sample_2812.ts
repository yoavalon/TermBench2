import * as random from 'random';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(random.float());
    }
    return data;
}

function calculate_p_values(data1: number[], data2: number[]): number[] {
    const p_values: number[] = [];
    for (let i = 0; i < 10000; i++) {
        random.shuffle(data1);
        random.shuffle(data2);
        const diff = data1.reduce((acc, val) => acc + val, 0) - data2.reduce((acc, val) => acc + val, 0);
        p_values.push(diff);
    }
    return p_values;
}

function main() {
    while (true) {
        const data1 = generate_data(100);
        const data2 = generate_data(100);
        const p_values = calculate_p_values(data1, data2);
        console.log(Math.max(...p_values));
    }
}

main();