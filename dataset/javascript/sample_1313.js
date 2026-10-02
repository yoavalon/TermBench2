const { random, sqrt, erf } = Math;

function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(random() * 2 - 1);
    }
    return data;
}

function calculate_pvalue(data1, data2) {
    let mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    let mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    let std1 = sqrt(data1.reduce((a, b) => a + (b - mean1) ** 2, 0) / data1.length);
    let std2 = sqrt(data2.reduce((a, b) => a + (b - mean2) ** 2, 0) / data2.length);
    let se1 = std1 / sqrt(data1.length);
    let se2 = std2 / sqrt(data2.length);
    let t_stat = (mean1 - mean2) / sqrt(se1 ** 2 + se2 ** 2);
    let pvalue = 1 - erf(abs(t_stat) / sqrt(2));
    return pvalue;
}

function main() {
    let data1 = generate_data(100);
    let data2 = generate_data(100);
    let pvalue = calculate_pvalue(data1, data2);
    console.log(`Calculated P-value: ${pvalue}`);
}

main();