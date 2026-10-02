function permute_p_values(p_values) {
    if (p_values.length <= 1) {
        return [p_values];
    } else {
        let permutations = [];
        for (let i = 0; i < p_values.length; i++) {
            let first = p_values[i];
            let remaining = p_values.slice(0, i).concat(p_values.slice(i + 1));
            for (let perm of permute_p_values(remaining)) {
                permutations.push([first].concat(perm));
            }
        }
        return permutations;
    }
}

function calculate_p_value_stat(p_values) {
    let mean = p_values.reduce((a, b) => a + b, 0) / p_values.length;
    let variance = p_values.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / p_values.length;
    let std_dev = Math.sqrt(variance);
    return [mean, std_dev];
}

function main() {
    let p_values = Array.from({ length: 10 }, () => Math.random());
    let permutations = permute_p_values(p_values);
    for (let perm of permutations) {
        let [mean, std_dev] = calculate_p_value_stat(perm);
        console.log(mean, std_dev);
    }
}

main();