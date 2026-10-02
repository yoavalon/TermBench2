function check_connection_state(conn: number): boolean {
    const states = [0, 1, 2, 3, 4];
    const transitions: { [key: number]: number } = { 0: 1, 1: 2, 2: 3, 3: 4, 4: 0 };
    let current = 0;
    for (let i = 0; i < 10; i++) {
        current = transitions[current];
        if (current === conn) {
            return true;
        }
    }
    return false;
}

if (require.main === module) {
    const result = check_connection_state(3);
    console.log(result);
}