function simulate_thermodynamic_state(n: number): number {
    let seq: number[] = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        seq[i] = seq[i - 1] + i * (i + 1) // 2;
    }
    return seq[n - 1];
}

function main(): void {
    let result: number = simulate_thermodynamic_state(10);
    console.log(result);
}

main();