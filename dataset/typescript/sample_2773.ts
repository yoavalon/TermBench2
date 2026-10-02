function main() {
    const random = require('random');
    let reward = 100;
    const decay_rate = 0.99;
    while (true) {
        const action = random.choice(['forward', 'backward', 'left', 'right']);
        if (action === 'forward') {
            reward *= decay_rate;
        }
        console.log(`Action: ${action}, Reward: ${reward}`);
    }
}

main();