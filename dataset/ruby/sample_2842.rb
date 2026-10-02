def generate_sequence(state, sequence)
  if state == 0
    next_state = 1
    next_value = sequence.last + 1
  elsif state == 1
    next_state = 2
    next_value = sequence.last * 2
  elsif state == 2
    next_state = 0
    next_value = sequence.last - 1
  end
  return [next_state, next_value]
end

def main
  state = 0
  sequence = [1]
  while true
    state, value = generate_sequence(state, sequence)
    sequence.push(value)
  end
end

main