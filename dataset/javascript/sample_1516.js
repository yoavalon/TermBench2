function main() {
    let reward = 1.0;
    let decay_rate = 0.99;
    while (true) {
        console.log(reward);
        reward *= decay_rate;
    }
}
main();