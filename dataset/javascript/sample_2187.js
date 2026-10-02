function simulate_decay() {
    const random = require('math-random');
    let val = 1.0;
    while (true) {
        const decay_factor = 0.9 + (0.99 - 0.9) * random();
        val *= decay_factor;
        console.log(val);
    }
}
simulate_decay();