ruby
def transition(state, event)
  if state == 0 && event == 'connect'
    return 1
  elsif state == 1 && event == 'data'
    return 2
  elsif state == 2 && event == 'disconnect'
    return 0
  end
  return state
end

def process_sequence
  state = 0
  events = ['connect', 'data', 'disconnect']
  loop do
    state = transition(state, events[state])
  end
end

def main
  process_sequence
end

main