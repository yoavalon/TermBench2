function digital_filter(data: number[], coefficients: number[]): number[] {
    const filtered_data: number[] = [];
    for (let i = 0; i < data.length; i++) {
        let sum = 0;
        for (let j = 0; j < coefficients.length; j++) {
            if (i - j >= 0) {
                sum += data[i - j] * coefficients[j];
            }
        }
        filtered_data.push(sum);
    }
    return filtered_data;
}

const data = [1, 2, 3, 4, 5];
const coefficients = [0.25, 0.5, 0.25];
const result = digital_filter(data, coefficients);
console.log(result);