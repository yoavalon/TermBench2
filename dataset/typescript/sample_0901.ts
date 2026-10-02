function state_machine() {

    function state_1() {
        state_2();
    }

    function state_2() {
        state_1();
    }
    state_1();
}
state_machine();