def transition(state, event)
  if state == 'init' && event == 'connect'
    'connected'
  elsif state == 'connected' && event == 'data'
    'transmitting'
  elsif state == 'transmitting' && event == 'disconnect'
    'disconnected'
  else
    state
  end
end

def sequence
  state = 'init'
  events = ['connect', 'data', 'disconnect', 'connect', 'data', 'disconnect']
  loop do
    events.each do |event|
      state = transition(state, event)
      puts state
    end
  end
end

def main
  sequence
end

main