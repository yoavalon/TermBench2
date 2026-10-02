function calculate_consensus(a: number, b: number, n: number): number {
    if (n === 0) {
        return a;
    } else {
        return calculate_consensus(b, (a + b) % 1000, n - 1);
    }
}

const result = calculate_consensus(1, 1, 10);
console.log(result);