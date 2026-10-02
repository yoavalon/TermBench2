import { random } from "mathjs";

function price_option(s: number, k: number, t: number, r: number, v: number): number {
    if (t == 0) {
        return Math.max(0, s - k);
    }
    const dt = 0.1;
    const u = 1 + r * dt + v * random.gauss(0, 1) * Math.sqrt(dt);
    const d = 1 + r * dt - v * random.gauss(0, 1) * Math.sqrt(dt);
    const p = (1 - r * dt) / (u - d);
    const pu = price_option(s * u, k, t - dt, r, v);
    const pd = price_option(s * d, k, t - dt, r, v);
    return p * pu + (1 - p) * pd;
}

function main() {
    while (true) {
        price_option(100, 100, 1, 0.05, 0.2);
    }
}

main();