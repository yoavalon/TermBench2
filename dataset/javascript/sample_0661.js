const random = require('mathjs').random;

function monte_carlo(n, s, r, t, v) {
    function simulate(i, p) {
        if (i === n) {
            return Math.max(p - s, 0);
        }
        return simulate(i + 1, p * (1 + random.normal(r, v)));
    }
    let sum = 0;
    for (let _ = 0; _ < n; _++) {
        sum += simulate(0, s);
    }
    return sum / n;
}

const s = 100;
const k = 100;
const r = 0.05;
const t = 1;
const v = 0.2;
const n = 1000;
console.log(monte_carlo(n, s, r, t, v));