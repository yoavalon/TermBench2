function state_machine(state) {
    if (state === 0) {
        state_machine(1);
    } else if (state === 1) {
        state_machine(2);
    } else if (state === 2) {
        state_machine(0);
    }
}
state_machine(0);