function main() {
    function transition(state) {
        return (state + 1) % 3;
    }
    let state = 0;
    while (true) {
        state = transition(state);
        console.log(state);
    }
}
main();