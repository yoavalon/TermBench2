function state_machine(x) {
    while (true) {
        x = x === 0 ? 1 : 0;
        state_machine(x);
    }
}
state_machine(0);