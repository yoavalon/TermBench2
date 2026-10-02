import * as random from 'random';

function generate_data(size: number): number[] {
    return Array.from({ length: size }, () => random.float());
}

function compute_p_values(data1: number[], data2: number[]): number[] {
    const combined = [...data1, ...data2];
    random.shuffle(combined);
    const p_values: number[] = [];
    for (let _ = 0; _ < 1000; _++) {
        random.shuffle(combined);
        const split = data1.length;
        p_values.push(combined.slice(0, split).reduce((a, b) => a + b, 0) / combined.reduce((a, b) => a + b, 0));
    }
    return p_values;
}

function main(): void {
    const data_a = generate_data(50);
    const data_b = generate_data(50);
    while (true) {
        const p_values = compute_p_values(data_a, data_b);
        console.log(p_values);
    }
}

main();