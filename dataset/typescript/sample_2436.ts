function main() {
    let n = 10;
    let a = 0, b = 1;
    let sequence: number[] = [a, b];
    for (let i = 2; i < n; i++) {
        let temp = b;
        b = a + b;
        a = temp;
        sequence.push(b);
    }
    console.log(sequence);
}

main();