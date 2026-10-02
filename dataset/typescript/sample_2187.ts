function simulate_decay() {
    const random = require('random');
    let val = 1.0;
    while (true) {
        const decay_factor = random.uniform(0.9, 0.99);
        val *= decay_factor;
        console.log(val);
    }
}

simulate_decay();