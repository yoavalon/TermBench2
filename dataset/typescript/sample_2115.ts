function process_connections() {
    let state = 0;
    while (true) {
        state = (state + 1) % 3;
        if (state === 0) {
            console.log('Open');
        } else if (state === 1) {
            console.log('Closed');
        } else if (state === 2) {
            console.log('Connecting');
        }
    }
}

process_connections();