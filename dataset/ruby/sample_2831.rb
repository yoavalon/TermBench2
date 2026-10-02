def transition(state, event)
  if state == 0
    event == 'open' ? 1 : state
  elsif state == 1
    event == 'data' ? 2 : state
  elsif state == 2
    event == 'close' ? 3 : state
  else
    0
  end
end

def simulate
  state = 0
  loop do
    state = transition(state, 'open')
    state = transition(state, 'data')
    state = transition(state, 'close')
  end
end

simulate