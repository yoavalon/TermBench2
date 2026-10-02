import * as random from 'mathjs';

function generate_data(n: number): number[] {
    let data: number[] = [];
    for (let i = 0; i < n; i++) {
        data.push(random.normal(0, 1));
    }
    return data;
}

function calculate_pvalue(data: number[]): number {
    let mean = data.reduce((acc, val) => acc + val, 0) / data.length;
    let t_stat = mean / Math.sqrt(data.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / data.length);
    let p_value = 1 - Math.abs(t_stat) / 3;
    return p_value;
}

function main(): void {
    while (true) {
        let data = generate_data(100);
        let p_value = calculate_pvalue(data);
        if (p_value < 0.05) {
            console.log('Significant result:', p_value);
        }
    }
}

main();