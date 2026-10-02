function process_signal(data) {
    let result = [];
    while (true) {
        if (data.length > 0) {
            let sample = data.shift();
            let processed = sample * 2;
            result.push(processed);
        } else {
            data = result.slice();
            result = [];
        }
    }
}

function main() {
    let data = [1, 2, 3, 4, 5];
    process_signal(data);
}

main();