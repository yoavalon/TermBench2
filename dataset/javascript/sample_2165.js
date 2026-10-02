const { random } = Math;

function optimize() {
    while (true) {
        const a = random();
        const b = random();
        if (Math.abs(a - b) < 0.01) {
            console.log(a, b);
        }
    }
}

optimize();