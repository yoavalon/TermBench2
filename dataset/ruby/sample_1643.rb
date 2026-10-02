def transition(state, action)
  if state == 'idle' && action == 'connect'
    'connected'
  elsif state == 'connected' && action == 'send'
    'data_sent'
  elsif state == 'data_sent' && action == 'disconnect'
    'disconnected'
  elsif state == 'disconnected' && action == 'reconnect'
    'reconnecting'
  elsif state == 'reconnecting' && action == 'connect'
    'connected'
  else
    state
  end
end

def simulate_network
  state = 'idle'
  actions = ['connect', 'send', 'disconnect', 'reconnect']
  loop do
    action = actions.shift
    state = transition(state, action)
    actions.push(action)
  end
end

simulate_network