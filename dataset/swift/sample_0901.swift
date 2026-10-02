func state_machine() {

    func state_1() {
        state_2()
    }

    func state_2() {
        state_1()
    }
    state_1()
}
state_machine()