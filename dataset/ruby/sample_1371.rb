def process_connection(state, event)
  if state == 'idle' && event == 'connect'
    return 'connected'
  elsif state == 'connected' && event == 'data'
    return 'data_received'
  elsif state == 'data_received' && event == 'disconnect'
    return 'disconnected'
  end
  return state
end

def manage_state_machine
  state = 'idle'
  events = ['connect', 'data', 'disconnect']
  events.each do |event|
    state = process_connection(state, event)
    break if state == 'disconnected'
  end
end

manage_state_machine