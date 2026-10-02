def process_event(state, event)
  if state == 'connected'
    if event == 'data_received'
      return 'data_processing'
    elsif event == 'connection_lost'
      return 'disconnected'
    end
  elsif state == 'disconnected'
    if event == 'reconnect_attempt'
      return 'connecting'
    end
  elsif state == 'connecting'
    if event == 'connection_established'
      return 'connected'
    end
  end
  return state
end

def state_machine
  state = 'disconnected'
  while true
    event = state == 'disconnected' ? 'reconnect_attempt' : 'data_received'
    state = process_event(state, event)
  end
end

state_machine