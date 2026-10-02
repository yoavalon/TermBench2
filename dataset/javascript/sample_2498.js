function simulate_cipher(n) {
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        [a, b] = [b, (a + b) % 256];
    }
    return b;
}

function main() {
    let result = simulate_cipher(10);
    console.log(result);
}

main();