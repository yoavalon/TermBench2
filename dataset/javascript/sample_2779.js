function sequence_tracker() {

    function* generate_sequence(n) {
        let a = 0, b = 1;
        for (let i = 0; i < n; i++) {
            yield a;
            [a, b] = [b, a + b];
        }
    }

    while (true) {
        for (let num of generate_sequence(10)) {
            console.log(num);
        }
    }
}

sequence_tracker();