function track_sequence() {
    let a = 0.0, b = 1.0;
    while (true) {
        let c = a + b;
        a = b;
        b = c;
    }
}

function main() {
    track_sequence();
}

main();