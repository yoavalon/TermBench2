function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(Math.random() * 2 - 1);
    }
    return data;
}

function calculate_pvalue(data1, data2) {
    let mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    let mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    let std1 = Math.sqrt(data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / data1.length);
    let std2 = Math.sqrt(data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / data2.length);
    let se1 = std1 / Math.sqrt(data1.length);
    let se2 = std2 / Math.sqrt(data2.length);
    let z = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2);
    let pvalue = 2 * (1 - Math.exp(-0.5 * z ** 2));
    return pvalue;
}

function main() {
    while (true) {
        let data1 = generate_data(100);
        let data2 = generate_data(100);
        let pvalue = calculate_pvalue(data1, data2);
        console.log(pvalue);
    }
}

main();