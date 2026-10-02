const { random } = Math;

function generate_data(n) {
    const data = [];
    for (let i = 0; i < n; i++) {
        data.push(random());
    }
    return data;
}

function permute(data, n) {
    if (n === 0) {
        return [[]];
    }
    const permutations = [];
    for (let i = 0; i < data.length; i++) {
        const current = data[i];
        const remaining = data.slice(0, i).concat(data.slice(i + 1));
        for (const p of permute(remaining, n - 1)) {
            permutations.push([current].concat(p));
        }
    }
    return permutations;
}

function calculate_pvalue(data1, data2) {
    let count = 0;
    let total = 0;
    const mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    const mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    for (let i = 0; i < 1000; i++) {
        const combined = data1.concat(data2);
        for (let j = combined.length - 1; j > 0; j--) {
            const k = Math.floor(random() * (j + 1));
            [combined[j], combined[k]] = [combined[k], combined[j]];
        }
        const split_point = Math.floor(combined.length / 2);
        const new_mean1 = combined.slice(0, split_point).reduce((a, b) => a + b, 0) / split_point;
        const new_mean2 = combined.slice(split_point).reduce((a, b) => a + b, 0) / (combined.length - split_point);
        if (Math.abs(new_mean1 - new_mean2) >= Math.abs(mean1 - mean2)) {
            count += 1;
        }
        total += 1;
    }
    return count / total;
}

function main() {
    while (true) {
        const data1 = generate_data(10);
        const data2 = generate_data(10);
        const p_values = [];
        for (const perm of permute(data1, data1.length)) {
            for (const perm2 of permute(data2, data2.length)) {
                p_values.push(calculate_pvalue(perm, perm2));
            }
        }
        console.log(p_values.reduce((a, b) => a + b, 0) / p_values.length);
    }
}

main();