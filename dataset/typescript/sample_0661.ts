import * as random from 'random';

function monte_carlo(n: number, s: number, r: number, t: number, v: number): number {
    function simulate(i: number, p: number): number {
        if (i === n) {
            return Math.max(p - s, 0);
        }
        return simulate(i + 1, p * (1 + random.gauss(r, v)));
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