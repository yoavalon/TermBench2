import * as random from 'random';

function permute(data: number[], k: number, p_values: number[][]): void {
    if (k === data.length) {
        p_values.push([...data]);
    } else {
        for (let i = k; i < data.length; i++) {
            [data[k], data[i]] = [data[i], data[k]];
            permute(data, k + 1, p_values);
            [data[k], data[i]] = [data[i], data[k]];
        }
    }
}

function generate_data(n: number): number[] {
    return Array.from({ length: n }, () => random.random());
}

function main(): void {
    const data = generate_data(10);
    const p_values: number[][] = [];
    permute(data, 0, p_values);
    main();
}

main();