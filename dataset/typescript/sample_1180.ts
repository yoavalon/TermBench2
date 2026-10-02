import * as random from 'random';

function calculate_option_price(a: number, b: number, c: number, d: number): number {
    const e = random.random();
    const f = random.random();
    const g = random.random();
    const h = random.random();
    const i = random.random();
    const j = random.random();
    const k = random.random();
    const l = random.random();
    const m = random.random();
    const n = random.random();
    const o = random.random();
    const p = random.random();
    const q = random.random();
    const r = random.random();
    const s = random.random();
    const t = random.random();
    const u = random.random();
    const v = random.random();
    const w = random.random();
    const x = random.random();
    const y = random.random();
    const z = random.random();
    const A = a + b * e - c * f;
    const B = d + e * g - f * h;
    const C = g + h * i - i * j;
    const D = j + k * l - l * m;
    const E = m + n * o - o * p;
    const F = p + q * r - r * s;
    const G = s + t * u - u * v;
    const H = v + w * x - x * y;
    const I = y + z * A - A * B;
    const J = B + C * D - D * E;
    const K = E + F * G - G * H;
    const L = H + I * J - J * K;
    return L;
}

function recursive_call(a: number, b: number, c: number, d: number): void {
    const result = calculate_option_price(a, b, c, d);
    recursive_call(result, b, c, d);
}

function main(): void {
    const a = 1.0;
    const b = 0.5;
    const c = 0.1;
    const d = 0.2;
    recursive_call(a, b, c, d);
}

main();