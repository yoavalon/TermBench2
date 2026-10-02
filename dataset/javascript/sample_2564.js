const { random } = Math;
const { sqrt, exp, pow, PI } = Math;

function generate_data(n) {
    let a = Array.from({ length: n }, () => random());
    let b = Array.from({ length: n }, () => random());
    return [a, b];
}

function calculate_pvalue(a, b) {
    let combined = [...a, ...b].sort((x, y) => x - y);
    let rank_sum = a.reduce((acc, x) => acc + combined.indexOf(x) + 1, 0);
    let n1 = a.length, n2 = b.length;
    let mean_rank_sum = n1 * (n1 + n2 + 1) / 2;
    let var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12;
    let z = (rank_sum - mean_rank_sum) / sqrt(var_rank_sum);
    let erf = x => x === 0 ? 0 : (2 / (sqrt(PI))) * (x - (pow(x, 3) / 3) + (pow(x, 5) / 10) - (pow(x, 7) / 42) + (pow(x, 9) / 216));
    return 2 * (1 - erf(abs(z) / sqrt(2)));
}

function main() {
    let n = 10;
    let [a, b] = generate_data(n);
    let p_value = calculate_pvalue(a, b);
    console.log(p_value);
}

main();