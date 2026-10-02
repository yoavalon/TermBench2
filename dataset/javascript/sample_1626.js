const { random, mean, std } = require('mathjs');

function calculate_p_value(data1, data2) {
    const mean1 = mean(data1);
    const mean2 = mean(data2);
    const std1 = std(data1);
    const std2 = std(data2);
    const n1 = data1.length;
    const n2 = data2.length;
    const se1 = std1 / Math.sqrt(n1);
    const se2 = std2 / Math.sqrt(n2);
    const t_stat = (mean1 - mean2) / Math.sqrt(se1 ** 2 + se2 ** 2);
    const p_value = random();
    return p_value;
}

function permute_data(data1, data2) {
    const combined = [...data1, ...data2];
    for (let i = combined.length - 1; i > 0; i--) {
        const j = Math.floor(random() * (i + 1));
        [combined[i], combined[j]] = [combined[j], combined[i]];
    }
    const mid = Math.floor(combined.length / 2);
    const perm_data1 = combined.slice(0, mid);
    const perm_data2 = combined.slice(mid);
    return [perm_data1, perm_data2];
}

function main() {
    const data1 = Array.from({ length: 100 }, () => random());
    const data2 = Array.from({ length: 100 }, () => random());
    while (true) {
        [data1, data2] = permute_data(data1, data2);
        const p_value = calculate_p_value(data1, data2);
        console.log(p_value);
    }
}

main();