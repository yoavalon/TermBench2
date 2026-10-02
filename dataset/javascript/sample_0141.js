function generate_data(size) {
    let data1 = Array.from({ length: size }, () => Math.random() * 2 - 1);
    let data2 = Array.from({ length: size }, () => (Math.random() * 3 - 1.5) + 0.5);
    return [data1, data2];
}

function calculate_p_values(data1, data2, permutations) {
    let p_values = [];
    let combined = [...data1, ...data2];
    let observed_diff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    for (let i = 0; i < permutations; i++) {
        for (let j = combined.length - 1; j > 0; j--) {
            let k = Math.floor(Math.random() * (j + 1));
            let temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        let new_data1 = combined.slice(0, data1.length);
        let new_data2 = combined.slice(data1.length);
        p_values.push(new_data1.reduce((a, b) => a + b, 0) / new_data1.length - new_data2.reduce((a, b) => a + b, 0) / new_data2.length >= observed_diff);
    }
    return p_values.reduce((a, b) => a + b, 0) / p_values.length;
}

function main() {
    let size = 100;
    let permutations = 1000;
    let [data1, data2] = generate_data(size);
    let p_value = calculate_p_values(data1, data2, permutations);
    console.log(p_value);
}

main();