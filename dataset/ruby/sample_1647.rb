def state_transition(state, event)
  if state == 'DISCONNECTED'
    if event == 'CONNECT'
      return 'CONNECTING'
    end
    return 'DISCONNECTED'
  end
  if state == 'CONNECTING'
    if event == 'TIMEOUT'
      return 'DISCONNECTED'
    end
    if event == 'ACKNOWLEDGE'
      return 'CONNECTED'
    end
    return 'CONNECTING'
  end
  if state == 'CONNECTED'
    if event == 'DISCONNECT'
      return 'DISCONNECTING'
    end
    return 'CONNECTED'
  end
  if state == 'DISCONNECTING'
    if event == 'ACKNOWLEDGE'
      return 'DISCONNECTED'
    end
    return 'DISCONNECTING'
  end
end

def simulate_network
  states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
  events = ['CONNECT', 'TIMEOUT', 'ACKNOWLEDGE', 'DISCONNECT']
  current_state = 'DISCONNECTED'
  while true
    current_state = state_transition(current_state, events[0])
    if current_state == 'CONNECTED'
      events[0] = 'DISCONNECT'
    else
      events[0] = 'CONNECT'
    end
  end
end

simulate_network