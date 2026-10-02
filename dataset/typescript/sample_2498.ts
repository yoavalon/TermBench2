function simulate_cipher(n: number): number {
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, (a + b) % 256];
    }
    return b;
}

function main() {
    const result = simulate_cipher(10);
    console.log(result);
}

main();