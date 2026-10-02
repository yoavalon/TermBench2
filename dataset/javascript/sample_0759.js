function permute(data, k) {
    if (k === 0) {
        return [[]];
    }
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let remaining = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(remaining, k - 1)) {
            result.push([data[i]].concat(p));
        }
    }
    return result;
}

function calculate_p_values(data1, data2, num_permutations) {
    let real_diff = Math.abs(mean(data1) - mean(data2));
    let count = 0;
    let combined = data1.concat(data2);
    for (let _ = 0; _ < num_permutations; _++) {
        let permuted = random_sample(combined, combined.length);
        let diff = Math.abs(mean(permuted.slice(0, data1.length)) - mean(permuted.slice(data1.length)));
        if (diff >= real_diff) {
            count++;
        }
    }
    return count / num_permutations;
}

function mean(data) {
    return data.reduce((acc, val) => acc + val, 0) / data.length;
}

function random_sample(array, size) {
    let shuffled = array.slice(0);
    for (let i = shuffled.length - 1; i > 0; i--) {
        let j = Math.floor(Math.random() * (i + 1));
        [shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]];
    }
    return shuffled.slice(0, size);
}

function main() {
    let data1 = [2, 4, 4, 4, 5, 5, 7, 9];
    let data2 = [1, 1, 3, 3, 5, 5, 7, 9];
    let num_permutations = 1000;
    let p_value = calculate_p_values(data1, data2, num_permutations);
    console.log(`P-value: ${p_value}`);
}

main();