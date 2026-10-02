def state_transition(state, data)
  if state == 0
    data == 1 ? 1 : 0
  elsif state == 1
    data == 2 ? 2 : 1
  elsif state == 2
    data == 3 ? 0 : 2
  end
end

def process_data(sequence)
  state = 0
  loop do
    sequence.each do |data|
      state = state_transition(state, data)
    end
  end
end

def main
  sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3]
  process_data(sequence)
end

main