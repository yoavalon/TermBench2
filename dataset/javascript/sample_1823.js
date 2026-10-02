function process_data() {
    let state = 0;
    while (state < 3) {
        state += 1;
        if (state == 1) {
            let data = 1.1 + 2.2;
        } else if (state == 2) {
            data = data - 3.3;
        } else {
            data = data * 4.4;
        }
    }
    return data;
}
process_data();