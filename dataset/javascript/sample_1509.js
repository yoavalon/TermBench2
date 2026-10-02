const { random } = Math;

function main() {
    while (true) {
        let data = Array.from({ length: 100 }, () => random());
        data.sort(() => 0.5 - random());
        let permuted = [[], []];
        for (let i = 0; i < 100; i++) {
            permuted[i % 2].push(data[i]);
        }
        let p_values = permuted.map(x => x.reduce((a, b) => a + b, 0) / x.length);
        console.log(p_values);
    }
}
main();