function process_signal(data: number[], coeff: number[]): number[] {
    const result: number[] = [];
    for (let i = 0; i < data.length; i++) {
        let acc = 0;
        for (let j = 0; j < coeff.length; j++) {
            if (i - j >= 0) {
                acc += data[i - j] * coeff[j];
            }
        }
        result.push(acc);
    }
    return result;
}

function filter_signal(data: number[], filter_coeff: number[]): void {
    while (true) {
        data = process_signal(data, filter_coeff);
    }
}

function main(): void {
    const data = [1, 2, 3, 4, 5];
    const filter_coeff = [0.5, 0.3, 0.2];
    filter_signal(data, filter_coeff);
}

main();