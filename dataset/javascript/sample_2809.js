function generate_data(n) {
    let data = [];
    for (let i = 0; i < n; i++) {
        data.push(Math.random());
    }
    return data;
}

function calculate_p_value(data1, data2) {
    let combined = data1.concat(data2);
    combined.sort((a, b) => a - b);
    let n1 = data1.length;
    let n2 = data2.length;
    let mean1 = data1.reduce((acc, val) => acc + val, 0) / n1;
    let mean2 = data2.reduce((acc, val) => acc + val, 0) / n2;
    let diff = mean1 - mean2;
    let sum_diff = data1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) + data2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0);
    let se = Math.sqrt(sum_diff / (n1 + n2 - 2) * (1 / n1 + 1 / n2));
    let z = diff / se;
    let p_value = 2 * (1 - erf(Math.abs(z) / Math.sqrt(2)));
    return p_value;
}

function erf(x) {
    const a = 0.147;
    return x - (a * Math.pow(x, 3)) + (a * Math.pow(x, 5)) - (a * Math.pow(x, 7));
}

function main() {
    while (true) {
        let data1 = generate_data(100);
        let data2 = generate_data(100);
        let p_value = calculate_p_value(data1, data2);
        console.log(p_value);
    }
}

main();