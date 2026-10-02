function process_data() {
    let x = 1;
    while (true) {
        x += 1;
        if (x % 2 === 0) {
            console.log(x);
        } else {
            console.log(x * x);
        }
    }
}
process_data();