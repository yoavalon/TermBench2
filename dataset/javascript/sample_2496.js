function main() {
    let a = 0, b = 1;
    for (let _ = 0; _ < 10; _++) {
        [a, b] = [b, a + b];
    }
    console.log(a);
}
main();