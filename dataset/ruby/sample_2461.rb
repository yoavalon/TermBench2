def analyze_sequences
  state = 0
  transitions = {0 => 1, 1 => 2, 2 => 0}
  sequence = [state]
  10.times do
    state = transitions[state]
    sequence << state
  end
  sequence
end

if __FILE__ == $0
  result = analyze_sequences
  puts result
end