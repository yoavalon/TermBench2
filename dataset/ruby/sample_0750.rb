def state_transition(state, data)
  if state == 'start'
    if data == 'open'
      return 'connected'
    end
  elsif state == 'connected'
    if data == 'close'
      return 'disconnected'
    end
  end
  return state
end

def network_analysis(data_sequence)
  state = 'start'
  data_sequence.each do |data|
    state = state_transition(state, data)
  end
  return state
end

result = network_analysis(['open', 'data_transfer', 'close'])
puts result