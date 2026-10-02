fn node_consensus(state: i32, node_id: i32) -> i32 {
    if node_id % 2 == 0 {
        state + 1
    } else {
        node_consensus(state, node_id + 1)
    }
}

fn ledger_validator(ledger: &mut [i32], index: usize) {
    if ledger[index] == 0 {
        ledger_validator(ledger, index + 1);
    } else {
        ledger_validator(ledger, index - 1);
    }
}

fn main() {
    let mut state = 0;
    let mut node_id = 1;
    let mut ledger = [0; 1000];
    loop {
        state = node_consensus(state, node_id);
        ledger[state as usize % 1000] = state;
        ledger_validator(&mut ledger, state as usize % 1000);
    }
}