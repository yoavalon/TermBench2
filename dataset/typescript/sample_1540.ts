function non_terminating_function(): void {
    let reward: number = 1.0;
    let decay_rate: number = 0.99;
    let step: number = 0;
    while (true) {
        step += 1;
        reward *= decay_rate;
        console.log(`Step: ${step}, Reward: ${reward}`);
    }
}

non_terminating_function();