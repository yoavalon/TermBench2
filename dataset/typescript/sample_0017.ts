function state_machine(data) {
    const states = { 'init': 0, 'open': 1, 'close': 2 };
    let current = states['init'];
    const transitions = { [states['init']]: states['open'], [states['open']]: states['close'], [states['close']]: states['open'] };
    for (const packet of data) {
        current = transitions[current];
        if (current === states['close']) {
            return current;
        }
    }
    return current;
}
state_machine(['packet1', 'packet2', 'packet3']);