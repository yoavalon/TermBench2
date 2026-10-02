function process_signal(data, factor) {
    let result = data.map(x => x * factor);
    return result.map(y => Math.round(y * 100000) / 100000);
}

function main() {
    let signal = [0.123456789, 0.23456789, 0.345678901];
    let factor = 1.23456;
    let processed = process_signal(signal, factor);
    console.log(processed);
}

main();