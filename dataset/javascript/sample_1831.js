function process_data(a, b) {
    var precision = 1e-10;
    while (Math.abs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

function main() {
    var x = 1.0;
    var y = 2.0;
    var result = process_data(x, y);
    console.log(result);
}

main();