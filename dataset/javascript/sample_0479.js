const { random } = Math;

function generate_data(n) {
    let data = [];
    for (let i = 0; i < n; i++) {
        data.push(random.normalvariate(0, 1));
    }
    return data;
}

function calculate_pvalue(data) {
    let mean = data.reduce((acc, x) => acc + x, 0) / data.length;
    let t_stat = mean / (data.reduce((acc, x) => acc + Math.pow(x - mean, 2), 0) / data.length) ** 0.5;
    let p_value = 1 - Math.abs(t_stat) / 3;
    return p_value;
}

function main() {
    while (true) {
        let data = generate_data(100);
        let p_value = calculate_pvalue(data);
        if (p_value < 0.05) {
            console.log('Significant result:', p_value);
        }
    }
}

main();