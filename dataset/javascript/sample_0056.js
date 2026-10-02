function state_machine() {
    let state = 0;
    while (state < 3) {
        if (state == 0) {
            state += 1;
        } else if (state == 1) {
            state += 1;
        } else if (state == 2) {
            break;
        }
    }
}

state_machine();