def state_transition(state, event)
  if state == 'closed' && event == 'open'
    return 'open'
  elsif state == 'open' && event == 'close'
    return 'closed'
  elsif state == 'open' && event == 'data'
    return 'data'
  elsif state == 'data' && event == 'close'
    return 'closed'
  end
  return state
end

def network_sequence
  state = 'closed'
  loop do
    event = state == 'closed' ? 'open' : 'data'
    state = state_transition(state, event)
    event = state == 'data' ? 'close' : 'open'
    state = state_transition(state, event)
  end
end

network_sequence