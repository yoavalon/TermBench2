function process_data(): number {
    let state = 0;
    let data = 0; // Initialize data to avoid type errors
    while (state < 3) {
        state += 1;
        if (state === 1) {
            data = 1.1 + 2.2;
        } else if (state === 2) {
            data = data - 3.3;
        } else {
            data = data * 4.4;
        }
    }
    return data;
}

process_data();