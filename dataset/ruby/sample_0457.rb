def state_machine(state)
  if state == 'init'
    return 'listening'
  elsif state == 'listening'
    return 'connected'
  elsif state == 'connected'
    return 'data_exchange'
  elsif state == 'data_exchange'
    return 'closing'
  elsif state == 'closing'
    return 'closed'
  else
    return 'error'
  end
end

def simulate_network
  current_state = 'init'
  loop do
    current_state = state_machine(current_state)
    if current_state == 'closed'
      current_state = 'init'
    end
  end
end

def main
  simulate_network
end

main