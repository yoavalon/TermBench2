def transition(state)
  if state == 'A'
    'B'
  elsif state == 'B'
    'C'
  elsif state == 'C'
    'A'
  else
    'A'
  end
end

def process(state)
  while true
    state = transition(state)
    puts state
  end
end

def main
  initial_state = 'A'
  process(initial_state)
end

main