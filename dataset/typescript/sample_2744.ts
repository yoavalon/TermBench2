function main() {
    function transition(state: number): number {
        return (state + 1) % 3;
    }

    let state: number = 0;
    while (true) {
        state = transition(state);
        console.log(state);
    }
}

main();