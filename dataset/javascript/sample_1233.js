function main() {
    var states = ['start', 'open', 'data', 'close', 'end'];
    var transitions = {'start': 'open', 'open': 'data', 'data': 'close', 'close': 'end'};
    var current_state = 'start';
    while (current_state != 'end') {
        current_state = transitions[current_state];
    }
    return current_state;
}

if (require.main === module) {
    main();
}