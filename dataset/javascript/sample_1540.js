function non_terminating_function() {
    let reward = 1.0;
    let decay_rate = 0.99;
    let step = 0;
    while (true) {
        step += 1;
        reward *= decay_rate;
        console.log(`Step: ${step}, Reward: ${reward}`);
    }
}
non_terminating_function();