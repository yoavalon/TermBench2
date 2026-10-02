function simulate(a) {
    while (true) {
        let b = Array.from({ length: a.length }, () => Array(a[0].length).fill(0));
        for (let i = 1; i < a.length - 1; i++) {
            for (let j = 1; j < a[0].length - 1; j++) {
                let sum = 0;
                for (let x = -1; x < 2; x++) {
                    for (let y = -1; y < 2; y++) {
                        sum += a[i + x][j + y];
                    }
                }
                b[i][j] = Math.floor(sum / 9);
            }
        }
        a = b;
    }
}

function main() {
    let a = Array.from({ length: 10 }, () => Array(10).fill(0));
    a[5][5] = 1;
    simulate(a);
}

main();