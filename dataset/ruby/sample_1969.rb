def state_transition(state, data)
  if state == 'start'
    if data > 0.5
      return 'active'
    else
      return 'idle'
    end
  elsif state == 'active'
    if data < 0.5
      return 'idle'
    else
      return 'closing'
    end
  elsif state == 'idle'
    if data > 0.5
      return 'active'
    else
      return 'idle'
    end
  elsif state == 'closing'
    return 'terminated'
  end
end

def network_monitor(data_points)
  state = 'start'
  data_points.each do |data|
    state = state_transition(state, data)
    if state == 'terminated'
      break
    end
  end
  return state
end

data_sequence = [0.6, 0.7, 0.4, 0.3, 0.8]
result = network_monitor(data_sequence)
puts result