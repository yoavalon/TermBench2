def transition(state, event)
  if state == 'init' && event == 'connect'
    'connected'
  elsif state == 'connected' && event == 'disconnect'
    'disconnected'
  elsif state == 'disconnected' && event == 'reconnect'
    'connected'
  else
    state
  end
end

def sequence(event_list)
  current_state = 'init'
  loop do
    event_list.each do |event|
      current_state = transition(current_state, event)
      yield current_state
    end
  end
end

def main
  events = ['connect', 'disconnect', 'reconnect', 'connect', 'disconnect']
  sequence(events) do |state|
    puts state
  end
end

main