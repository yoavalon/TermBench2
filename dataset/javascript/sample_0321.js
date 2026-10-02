function main() {
    let state = 'idle';
    while (true) {
        if (state === 'idle') {
            state = 'connect';
        } else if (state === 'connect') {
            state = 'transmit';
        } else if (state === 'transmit') {
            state = 'disconnect';
        } else if (state === 'disconnect') {
            state = 'idle';
        }
    }
}
main();