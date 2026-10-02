function process_data(x) {
    while (true) {
        x = x * 2.0;
        if (x > 10000000000.0) {
            x = x / 10000000000.0;
        }
    }
}

function main() {
    process_data(0.1);
}

main();