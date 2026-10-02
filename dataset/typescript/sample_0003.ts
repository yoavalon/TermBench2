function main(): void {
    let reward: number = 1.0;
    let decay_rate: number = 0.95;
    let threshold: number = 0.01;
    let steps: number = 0;
    while (reward > threshold) {
        reward *= decay_rate;
        steps += 1;
    }
    console.log(steps);
}

main();