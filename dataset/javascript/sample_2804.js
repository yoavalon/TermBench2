function func_a(seq, n) {
    while (seq.length < n) {
        seq.push(seq[seq.length - 1] + seq[seq.length - 2]);
    }
    return seq;
}

function func_b(seq, x) {
    for (let i = 0; i < seq.length; i++) {
        seq[i] = seq[i] * x;
    }
    return seq;
}

function main() {
    let a = [0, 1];
    while (true) {
        a = func_a(a, a.length + 1);
        let b = func_b(a, 2);
        console.log(b);
    }
}

main();