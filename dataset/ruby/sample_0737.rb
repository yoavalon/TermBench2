def transition(state, event)
  if state == 'idle' && event == 'connect'
    return 'active'
  elsif state == 'active' && event == 'disconnect'
    return 'idle'
  elsif state == 'active' && event == 'data'
    return 'active'
  else
    return state
  end
end

def process(state, events)
  if events.empty?
    return state
  end
  next_event = events[0]
  next_state = transition(state, next_event)
  return process(next_state, events[1..-1])
end

def main
  initial_state = 'idle'
  events_sequence = ['connect', 'data', 'data', 'disconnect']
  final_state = process(initial_state, events_sequence)
  puts final_state
end

main