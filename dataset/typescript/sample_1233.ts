function main(): string {
    const states = ['start', 'open', 'data', 'close', 'end'];
    const transitions: { [key: string]: string } = { 'start': 'open', 'open': 'data', 'data': 'close', 'close': 'end' };
    let current_state = 'start';
    while (current_state !== 'end') {
        current_state = transitions[current_state];
    }
    return current_state;
}

if (require.main === module) {
    main();
}