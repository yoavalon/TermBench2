import { shuffle } from 'lodash';

function* permute(data: number[], i: number, length: number): Generator<number[]> {
    if (i === length) {
        yield data;
    } else {
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            yield* permute(data, i + 1, length);
            [data[i], data[j]] = [data[j], data[i]];
        }
    }
}

function calculate_p_value(observed: number, samples: number[]): number {
    let count = 0;
    for (const sample of samples) {
        if (sample >= observed) {
            count += 1;
        }
    }
    return count / samples.length;
}

function generate_samples(data: number[], n: number): number[] {
    const samples: number[] = [];
    for (let _ = 0; _ < n; _++) {
        const permuted_data = Array.from(permute([...data], 0, data.length));
        const sample = permuted_data.map(sum).reduce((a, b) => a + b, 0);
        samples.push(sample);
    }
    return samples;
}

function sum(arr: number[]): number {
    return arr.reduce((a, b) => a + b, 0);
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const observed = sum(data);
    const n = 10000;
    const samples = generate_samples(data, n);
    const p_value = calculate_p_value(observed, samples);
    console.log(p_value);
}

main();