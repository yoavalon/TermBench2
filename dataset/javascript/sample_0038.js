function process_signal(data, threshold) {
    let processed = [];
    for (let x of data) {
        if (Math.abs(x) > threshold) {
            processed.push(x);
        } else {
            break;
        }
    }
    return processed;
}

function main() {
    let data = [0.1, 0.5, 1.5, 2.5, 0.3, 0.4];
    let threshold = 1.0;
    let result = process_signal(data, threshold);
    console.log(result);
}

main();