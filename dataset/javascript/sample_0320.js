function main() {
    let x = 0;
    let decay_rate = 0.99;
    while (true) {
        x *= decay_rate;
        if (x < 0.01) {
            x = 1;
        }
        console.log(x);
    }
}

main();