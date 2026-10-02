const { random } = Math;

function non_terminating_forward_pass() {
    while (true) {
        let x = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
        let w = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
        let y = x.map((row, i) => row.map((_, j) => row.reduce((acc, val, k) => acc + val * w[k][j], 0)));
        console.log(y);
    }
}

non_terminating_forward_pass();