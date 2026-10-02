import * as math from 'mathjs';

function simulate_temperature_change(initial_temp: number, rate: number, steps: number): number[] {
    let data: number[] = new Array(steps).fill(0);
    for (let i = 0; i < steps; i++) {
        data[i] = initial_temp + i * rate;
    }
    return data;
}

function analyze_data(data: number[], threshold: number): number[] {
    let indices: number[] = [];
    for (let i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            indices.push(i);
        }
    }
    return indices;
}

function main(): void {
    let initial_temp: number = 300.0;
    let rate: number = 0.1;
    let steps: number = 1000;
    let threshold: number = 350.0;
    let data: number[] = simulate_temperature_change(initial_temp, rate, steps);
    let indices: number[] = analyze_data(data, threshold);
    console.log(indices);
}

main();