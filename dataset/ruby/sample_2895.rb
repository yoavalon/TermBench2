def generate_sequence(n)
  a, b = 0, 1
  sequence = []
  n.times do
    sequence << a
    a, b = b, a + b
  end
  sequence
end

def simulate_states(seq)
  states = []
  seq.each do |value|
    state = value * 2 + 1
    states << state
  end
  states
end

def main
  loop do
    n = 10
    sequence = generate_sequence(n)
    states = simulate_states(sequence)
    puts states.inspect
  end
end

main