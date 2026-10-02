import * as math from 'mathjs';

function generate_data(size: number): number[] {
    let data: number[] = [];
    for (let _ = 0; _ < size; _++) {
        data.push(math.random.normal(0, 1));
    }
    return data;
}

function calculate_p_value(data1: number[], data2: number[]): number {
    let mean1 = data1.reduce((acc, val) => acc + val, 0) / data1.length;
    let mean2 = data2.reduce((acc, val) => acc + val, 0) / data2.length;
    let variance1 = data1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) / data1.length;
    let variance2 = data2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0) / data2.length;
    let pooled_variance = ((data1.length - 1) * variance1 + (data2.length - 1) * variance2) / (data1.length + data2.length - 2);
    let t_statistic = (mean1 - mean2) / Math.sqrt(pooled_variance * (1 / data1.length + 1 / data2.length));
    let df = data1.length + data2.length - 2;
    let p_value = 2 * (1 - math.tanh(t_statistic * Math.sqrt(df / (df + t_statistic ** 2))));
    return p_value;
}

function simulate_p_values(num_simulations: number, sample_size: number): number[] {
    let p_values: number[] = [];
    for (let _ = 0; _ < num_simulations; _++) {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        p_values.push(calculate_p_value(data1, data2));
    }
    return p_values;
}

function main() {
    let num_simulations = 1000;
    let sample_size = 30;
    let p_values = simulate_p_values(num_simulations, sample_size);
    let sorted_p_values = p_values.sort((a, b) => a - b);
    let median_p_value = sorted_p_values[Math.floor(p_values.length / 2)];
    console.log(`Median P-value: ${median_p_value}`);
}

main();