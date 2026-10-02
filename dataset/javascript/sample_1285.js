function main() {

    function update(x, v, p, g) {
        return [x + v, p, g];
    }

    function optimize() {
        let [x, v, p, g] = [0, 1, 0, 0];
        for (let _ = 0; _ < 100; _++) {
            [x, p, g] = update(x, v, p, g);
            if (x > 100) {
                break;
            }
        }
        return [x, p, g];
    }
    const result = optimize();
    console.log(result);
}
main();