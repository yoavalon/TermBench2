function permute_p_values(data, target, perm_count, depth = 0) {
    if (depth == perm_count) {
        return [];
    }
    data.sort(() => Math.random() - 0.5);
    return [(data.reduce((a, b) => a + b, 0) / data.length)] + permute_p_values(data, target, perm_count, depth + 1);
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let target = 3;
    let perm_count = 10;
    let results = permute_p_values(data, target, perm_count);
    console.log(results);
}

main();