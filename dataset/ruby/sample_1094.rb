def node_consensus(state, node_id)
  if node_id % 2 == 0
    state + 1
  else
    node_consensus(state, node_id + 1)
  end
end

def ledger_validator(ledger, index)
  if ledger[index] == 0
    ledger_validator(ledger, index + 1)
  else
    ledger_validator(ledger, index - 1)
  end
end

def main
  state = 0
  node_id = 1
  ledger = Array.new(1000, 0)
  loop do
    state = node_consensus(state, node_id)
    ledger[state % 1000] = state
    ledger_validator(ledger, state % 1000)
  end
end

main