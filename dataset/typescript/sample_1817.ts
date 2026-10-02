import * as math from 'mathjs';

function financial_simulation(n: number, s: number, r: number, t: number, v: number): number {
    let dt = t / n;
    let st = s * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * math.randomNormal(0, 1, n));
    return math.mean(math.max(st.map(x => x - s), 0));
}

financial_simulation(10000, 100, 0.05, 1, 0.2);