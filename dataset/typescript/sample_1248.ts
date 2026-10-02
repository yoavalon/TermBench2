function main(): void {
    const gamma: number = 0.99;
    const rewards: number[] = [100, 50, 25, 10, 5];
    let state_value: number = 0;
    for (const r of rewards) {
        state_value = gamma * state_value + r;
    }
    console.log(state_value);
}

main();