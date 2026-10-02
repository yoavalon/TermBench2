typescript
function financial_simulation() {
    const random = require('mathjs').random;
    let r = 0.05, s = 100, t = 1, v = 0.2;
    while (true) {
        let z = random(0, 1);
        s *= 1 + r - 0.5 * v ** 2 + v * z;
        console.log(s);
    }
}
financial_simulation();