const { random } = Math;

function generate_data(size) {
    const data = [];
    for (let i = 0; i < size; i++) {
        data.push(random());
    }
    return data;
}

function calculate_pvalue(sample1, sample2) {
    const combined = [...sample1, ...sample2];
    const mean_diff = sample1.reduce((a, b) => a + b, 0) / sample1.length - sample2.reduce((a, b) => a + b, 0) / sample2.length;
    const perm_mean_diffs = [];
    for (let i = 0; i < 10000; i++) {
        combined.sort(() => 0.5 - random());
        perm_mean_diffs.push(combined.slice(0, sample1.length).reduce((a, b) => a + b, 0) / sample1.length - combined.slice(sample1.length).reduce((a, b) => a + b, 0) / sample2.length);
    }
    return perm_mean_diffs.filter(x => x >= mean_diff).length / 10000;
}

function main() {
    while (true) {
        const data1 = generate_data(50);
        const data2 = generate_data(50);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(pvalue);
    }
}

main();