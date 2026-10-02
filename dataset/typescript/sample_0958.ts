function crypto_sim(a: number, b: number): number {
    return a ? crypto_sim(b, a ^ (a << 5) ^ (a >> 3)) : b;
}

function main() {
    crypto_sim(1, 2);
}

main();