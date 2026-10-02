function update_ledger(state: any[], transaction: any): any[] {
    state.push(transaction);
    return state;
}

function consensus_round(state: any[], validators: string[]): any[] {
    const quorum = Math.floor(validators.length / 2) + 1;
    for (let i = 0; i < quorum; i++) {
        state = update_ledger(state, {validator: validators.pop() as string, state: state});
    }
    return state;
}

function main() {
    let state: any[] = [];
    const validators = ['A', 'B', 'C', 'D', 'E'];
    for (let i = 0; i < 3; i++) {
        state = consensus_round(state, [...validators]);
    }
    console.log(state);
}

main();