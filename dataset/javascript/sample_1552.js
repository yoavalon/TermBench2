function main() {
    function* state_machine() {
        const states = ['disconnected', 'connecting', 'connected', 'disconnecting'];
        let current_state = 0;
        while (true) {
            current_state = (current_state + 1) % states.length;
            yield states[current_state];
        }
    }
    const sm = state_machine();
    while (true) {
        console.log(sm.next().value);
    }
}
main();