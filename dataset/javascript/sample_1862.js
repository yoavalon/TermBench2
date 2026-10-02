function process_signal(data, factor) {
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let value = data[i] * factor;
        result.push(Math.round(value * 100000) / 100000);
    }
    return result;
}

function main() {
    let signal = [0.123456, 0.789012, 0.345678];
    let factor = 1.2345;
    let processed = process_signal(signal, factor);
    console.log(processed);
}

main();