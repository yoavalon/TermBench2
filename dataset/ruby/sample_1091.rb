def update_ledger(state, block)
  new_state = state.dup
  new_state[block['hash']] = block['data']
  return new_state
end

def verify_block(block, prev_hash)
  return block['prev_hash'] == prev_hash
end

def process_transaction(state, block)
  if verify_block(block, state.keys.last)
    return update_ledger(state, block)
  end
  return state
end

def main
  ledger = {'genesis' => 'initial_state'}
  while true
    new_block = {'hash' => 'block_hash', 'data' => 'transaction_data', 'prev_hash' => ledger.keys.last}
    ledger = process_transaction(ledger, new_block)
  end
end

main