def update_ledger(state, transaction):
    state.append(transaction)
    return state

def consensus_round(state, validators):
    quorum = len(validators) // 2 + 1
    for _ in range(quorum):
        state = update_ledger(state, {'validator': validators.pop(), 'state': state})
    return state

def main():
    state = []
    validators = ['A', 'B', 'C', 'D', 'E']
    for _ in range(3):
        state = consensus_round(state, validators.copy())
    print(state)
main()