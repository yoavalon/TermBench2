def transition(state, event)
  if state == 'init' && event == 'connect'
    return 'connected'
  elsif state == 'connected' && event == 'disconnect'
    return 'disconnected'
  elsif state == 'disconnected' && event == 'reconnect'
    return 'connected'
  else
    return state
  end
end

def run
  states = ['init', 'connected', 'disconnected']
  events = ['connect', 'disconnect', 'reconnect']
  current_state = 'init'
  event_sequence = ['connect', 'disconnect', 'reconnect', 'disconnect']
  event_sequence.each do |event|
    current_state = transition(current_state, event)
    break if !states.include?(current_state)
  end
  puts current_state
end

run