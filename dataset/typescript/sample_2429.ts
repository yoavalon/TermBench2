function generate_sequence(n: number): number[] {
    let sequence: number[] = new Array(n).fill(0);
    sequence[0] = 0;
    sequence[1] = 1;
    for (let i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

function main(): void {
    let data: number[] = generate_sequence(10);
    console.log(data);
}

main();