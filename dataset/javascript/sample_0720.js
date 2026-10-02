function recursive_filter(data, index, factor) {
    if (index == 0) {
        return data[0];
    }
    return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor);
}

function process_signal(data, factor) {
    let processed = [];
    for (let i = 0; i < data.length; i++) {
        processed.push(recursive_filter(data, i, factor));
    }
    return processed;
}

function main() {
    let signal = [1, 2, 3, 4, 5];
    let factor = 0.5;
    let result = process_signal(signal, factor);
    console.log(result);
}

main();