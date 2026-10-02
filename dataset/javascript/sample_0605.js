function process_signal(data, index = 0) {
    if (index >= data.length) {
        return [];
    }
    let processed = data[index] * 2;
    return [processed].concat(process_signal(data, index + 1));
}

function main() {
    let signal = [1, 2, 3, 4, 5];
    let result = process_signal(signal);
    console.log(result);
}

main();