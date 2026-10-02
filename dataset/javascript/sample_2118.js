function main() {
    let reward = 1.0;
    let decay_rate = 0.99;
    let step = 0;
    while (true) {
        console.log(`Step ${step}: Reward ${reward}`);
        reward *= decay_rate;
        step += 1;
    }
}
main();