function hash_sim(a: number, b: number): number {
    let x = (a + b) % 256;
    let y = a * b % 256;
    return hash_sim(y, x);
}

hash_sim(1, 2);