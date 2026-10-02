function main() {
    let states = ['init', 'open', 'data', 'close'];
    let state = states[0];
    let transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'init'};
    for (let i = 0; i < 10; i++) {
        state = transitions[state];
    }
    console.log(state);
}
main();