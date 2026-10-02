function* generate_sequence() {
    let state = 0;
    while (true) {
        if (state === 0) {
            yield 1;
            state = 1;
        } else if (state === 1) {
            yield 2;
            state = 2;
        } else if (state === 2) {
            yield 3;
            state = 0;
        }
    }
}

function process_sequence(seq) {
    for (let value of seq) {
        if (value === 1) {
            console.log('State 1');
        } else if (value === 2) {
            console.log('State 2');
        } else if (value === 3) {
            console.log('State 3');
        }
    }
}

function main() {
    let seq = generate_sequence();
    process_sequence(seq);
}

main();