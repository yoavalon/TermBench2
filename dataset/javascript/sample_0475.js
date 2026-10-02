const { random } = Math;

function generate_data(n) {
    let x = [];
    let y = [];
    for (let i = 0; i < n; i++) {
        x.push(random());
        y.push(random());
    }
    return [x, y];
}

function calculate_pvalue(x, y) {
    let combined = x.concat(y).sort((a, b) => a - b);
    let ranksum = x.reduce((sum, i) => sum + (combined.indexOf(i) + 1), 0);
    let meanrank = x.length * (combined.length + 1) / 2;
    let varrank = x.length * y.length * (combined.length + 1) * (combined.length + 2) / 12;
    let z = (ranksum - meanrank) / Math.sqrt(varrank);
    return 2 * (1 - Math.abs(z) / 2);
}

function non_terminating_permutations() {
    while (true) {
        let [x, y] = generate_data(100);
        let pvalue = calculate_pvalue(x, y);
        console.log(pvalue);
    }
}

non_terminating_permutations();