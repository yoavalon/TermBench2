def transition(state, event)
  if state == 'idle' && event == 'connect'
    'connected'
  elsif state == 'connected' && event == 'data'
    'data_received'
  elsif state == 'data_received' && event == 'disconnect'
    'disconnected'
  else
    state
  end
end

def process_events(events)
  current_state = 'idle'
  events.each do |event|
    current_state = transition(current_state, event)
    break if current_state == 'disconnected'
  end
  current_state
end

def main
  events = ['connect', 'data', 'disconnect', 'connect']
  final_state = process_events(events)
  puts final_state
end

main