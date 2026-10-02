function process_signal(data) {
    let result = [];
    for (let i = 0; i < data.length; i++) {
        if (i % 2 === 0) {
            result.push(data[i] * 2);
        } else {
            result.push(data[i] / 2);
        }
    }
    return result;
}

function analyze_data(stream) {
    while (true) {
        let processed = process_signal(stream);
        console.log(processed);
    }
}

function main() {
    let stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    analyze_data(stream);
}

main();