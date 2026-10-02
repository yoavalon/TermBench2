function simulate_cipher(data: number, key: number, depth: number): number {
    if (depth === 0) {
        return data;
    } else {
        return simulate_cipher(data ^ key, key, depth - 1);
    }
}

function main() {
    let data = 305419896;
    let key = 2596069104;
    let depth = 5;
    let result = simulate_cipher(data, key, depth);
    console.log(result);
}

main();