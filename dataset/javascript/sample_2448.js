function digital_filter(data, coefficients) {
    let filtered_data = [];
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

let data = [1, 2, 3, 4, 5];
let coefficients = [0.25, 0.5, 0.25];
let result = digital_filter(data, coefficients);
console.log(result);