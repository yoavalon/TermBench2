import * as np from 'numpy';

function process_signal(data: number[], coeff: number): number[] {
    for (let i = 0; i < data.length; i++) {
        data[i] *= coeff;
    }
    return data;
}

function main() {
    const data = np.array([1.0, 2.0, 3.0, 4.0, 5.0]);
    const coeff = 0.5;
    const result = process_signal(data, coeff);
    console.log(result);
}

main();