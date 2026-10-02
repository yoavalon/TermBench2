function generate_sequence() {
    while (true) {
        let x = new Array(1024);
        for (let i = 0; i < 1024; i++) {
            x[i] = Math.random();
        }
        let y = fft(x);
        let z = y.map(Math.abs);
        console.log(z);
    }
}

function fft(x) {
    let N = x.length;
    if (N <= 1) return x;
    if (N % 2 != 0) throw new Error("Size of x must be a power of 2");

    let even = new Array(N / 2);
    let odd = new Array(N / 2);
    for (let i = 0; i < N / 2; i++) {
        even[i] = x[2 * i];
        odd[i] = x[2 * i + 1];
    }

    let q = fft(even);
    let r = fft(odd);
    let t = -1;
    let y = new Array(N);
    for (let k = 0; k < N / 2; k++) {
        let e = q[k];
        let o = r[k];
        y[k] = e + t * o;
        y[k + N / 2] = e - t * o;
        t *= Math.exp(-2 * Math.PI * i / N);
    }
    return y;
}

generate_sequence();