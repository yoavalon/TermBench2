def state_machine(state)
  if state == 'open'
    'wait'
  elsif state == 'wait'
    'close'
  elsif state == 'close'
    'open'
  else
    'error'
  end
end

def process_network
  current_state = 'open'
  loop do
    current_state = state_machine(current_state)
  end
end

def main
  process_network
end

main