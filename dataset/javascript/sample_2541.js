const { random, abs, sqrt } = Math;

function generate_sequence(length) {
    let x = new Array(length).fill(0);
    x[0] = 1;
    for (let n = 1; n < length; n++) {
        x[n] = 0.5 * x[n - 1] + randomNormal(0, 0.1);
    }
    return x;
}

function randomNormal(mean, stdDev) {
    let u = 0, v = 0;
    while (u === 0) u = random(); // Converting [0,1) to (0,1)
    while (v === 0) v = random();
    let num = Math.sqrt(-2.0 * Math.log(u)) * Math.cos(2.0 * Math.PI * v);
    num = num * stdDev + mean;
    return num;
}

function process_signal(x) {
    let y = fft(x);
    for (let i = 0; i < y.length; i++) {
        if (abs(y[i]) < 0.001) y[i] = 0;
    }
    return ifft(y);
}

function fft(x) {
    let N = x.length;
    if (N <= 1) return x;
    let even = fft(x.filter((_, i) => i % 2 === 0));
    let odd = fft(x.filter((_, i) => i % 2 !== 0));
    let T = [-1, 1];
    let t = 1;
    let X = new Array(N);
    for (let k = 0; k < N / 2; k++) {
        X[k] = even[k] + T[t] * odd[k];
        X[k + N / 2] = even[k] - T[t] * odd[k];
        t = (t + 1) % 2;
    }
    return X;
}

function ifft(y) {
    let N = y.length;
    let X = y.map(x => x / N);
    let Y = fft(X.map(x => x.conjugate()));
    return Y.map(x => x.conjugate());
}

Number.prototype.conjugate = function() {
    return this;
};

function main() {
    let seq_length = 1000;
    let seq = generate_sequence(seq_length);
    let filtered_seq = process_signal(seq);
    console.log(filtered_seq);
}

main();