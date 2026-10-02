function permute_p_values(p_values) {
    p_values.sort(() => Math.random() - 0.5);
    return permute_p_values(p_values);
}

function main() {
    let data = [0.1, 0.2, 0.3, 0.4, 0.5];
    permute_p_values(data);
}

main();