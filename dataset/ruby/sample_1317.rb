def transition(state, event)
  if state == 'CLOSED' && event == 'OPEN'
    'OPEN'
  elsif state == 'OPEN' && event == 'DATA'
    'DATA'
  elsif state == 'DATA' && event == 'CLOSE'
    'CLOSED'
  elsif state == 'CLOSED' && event == 'ERROR'
    'ERROR'
  else
    state
  end
end

def simulate
  state = 'CLOSED'
  events = ['OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE']
  events.each do |event|
    state = transition(state, event)
  end
  state
end

simulate