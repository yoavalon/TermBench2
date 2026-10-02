function state_machine(state: string, steps: number): string {
    if (!steps) {
        return state;
    }
    if (state === 'open') {
        return state_machine('close', steps - 1);
    }
    if (state === 'close') {
        return state_machine('open', steps - 1);
    }
    return state;
}

function main() {
    console.log(state_machine('open', 5));
}

main();