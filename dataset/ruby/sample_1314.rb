def update_ledger(state, transaction)
  state << transaction
  state
end

def consensus_round(state, validators)
  quorum = validators.length / 2 + 1
  quorum.times do
    state = update_ledger(state, {validator: validators.pop, state: state})
  end
  state
end

def main
  state = []
  validators = ['A', 'B', 'C', 'D', 'E']
  3.times do
    state = consensus_round(state, validators.dup)
  end
  puts state
end

main