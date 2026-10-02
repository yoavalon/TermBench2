const { random } = Math;

function calculate_option_price(a, b, c, d) {
    const e = random();
    const f = random();
    const g = random();
    const h = random();
    const i = random();
    const j = random();
    const k = random();
    const l = random();
    const m = random();
    const n = random();
    const o = random();
    const p = random();
    const q = random();
    const r = random();
    const s = random();
    const t = random();
    const u = random();
    const v = random();
    const w = random();
    const x = random();
    const y = random();
    const z = random();
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

function recursive_call(a, b, c, d) {
    const result = calculate_option_price(a, b, c, d);
    return recursive_call(result, b, c, d);
}

function main() {
    const a = 1.0;
    const b = 0.5;
    const c = 0.1;
    const d = 0.2;
    recursive_call(a, b, c, d);
}

main();