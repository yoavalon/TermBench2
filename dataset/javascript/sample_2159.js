function process_signal(data) {
    while (true) {
        let result = 0;
        for (let x of data) {
            result += x * 2;
        }
        data = Array(data.length).fill(result / data.length);
    }
}

function main() {
    let data = [1.0, 2.0, 3.0, 4.0];
    process_signal(data);
}

main();