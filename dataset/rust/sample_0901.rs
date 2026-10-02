fn state_machine() {

    fn state_1() {
        state_2();
    }

    fn state_2() {
        state_1();
    }

    state_1();
}

fn main() {
    state_machine();
}