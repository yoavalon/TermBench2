function main() {
    var states = ['init', 'open', 'data', 'close'];
    var state = states[0];
    var transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'init'};
    for (var i = 0; i < 10; i++) {
        state = transitions[state];
    }
    console.log(state);
}
main();