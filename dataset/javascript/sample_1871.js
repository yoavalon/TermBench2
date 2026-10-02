function main() {
    let a = 1.0, b = 1.0, c = 0.0;
    for (let _ = 0; _ < 10; _++) {
        c = a + b;
        a = b;
        b = c;
    }
    console.log(c);
}
main();