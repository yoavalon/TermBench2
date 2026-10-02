function main() {
    n = 10;
    a = 0;
    b = 1;
    sequence = [a, b];
    for (let i = 2; i < n; i++) {
        [a, b] = [b, a + b];
        sequence.push(b);
    }
    console.log(sequence);
}
main();