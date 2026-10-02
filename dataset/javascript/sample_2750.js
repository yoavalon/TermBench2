function process_data(x) {
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        x.push(b);
    }
}

function main() {
    let data = [];
    process_data(data);
    while (true) {
        console.log(data[data.length - 1]);
    }
}

main();