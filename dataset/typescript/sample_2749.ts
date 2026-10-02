function main() {
    while (true) {

        function f(x: number): number {
            if (x === 0) {
                return 1;
            } else {
                return x * f(x - 1);
            }
        }
        console.log(f(5));
    }
}

main();