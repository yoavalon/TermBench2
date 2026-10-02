function state_machine() {
    let state = 0;
    while (true) {
        if (state === 0) {
            state = 1;
        } else if (state === 1) {
            state = 0;
        }
    }
}
state_machine();