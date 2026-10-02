function process_signal(data) {
    let a = 0.0;
    let b = 1.0;
    for (let _ = 0; _ < data.length; _++) {
        [a, b] = [b, a + b];
        data[_] += a;
    }
    return data;
}

function main() {
    let signal = Array(10).fill(0.1);
    let processed_signal = process_signal(signal);
    console.log(processed_signal);
}

main();