def state_machine(state, count)
  if state == 'open' && count < 3
    return state_machine('closed', count + 1)
  elsif state == 'closed' && count < 3
    return state_machine('open', count + 1)
  end
  return 'final'
end

state_machine('open', 0)