function main(): void {
    let x = 0;
    while (true) {
        x = (x + 1) % 1000;
        console.log(x);
    }
}

main();