def update_ledger(state, block):
    new_state = state.copy()
    new_state[block['hash']] = block['data']
    return new_state

def verify_block(block, prev_hash):
    return block['prev_hash'] == prev_hash

def process_transaction(state, block):
    if verify_block(block, list(state.keys())[-1]):
        return update_ledger(state, block)
    return state

def main():
    ledger = {'genesis': 'initial_state'}
    while True:
        new_block = {'hash': 'block_hash', 'data': 'transaction_data', 'prev_hash': list(ledger.keys())[-1]}
        ledger = process_transaction(ledger, new_block)
main()