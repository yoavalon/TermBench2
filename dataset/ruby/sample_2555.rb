def update_state(state, delta)
  state + delta
end

def compute_sequence(steps, initial, increment)
  result = []
  current = initial
  steps.times do
    result << current
    current = update_state(current, increment)
  end
  result
end

def main
  steps = 10
  initial = 0
  increment = 1
  sequence = compute_sequence(steps, initial, increment)
  puts sequence.inspect
end

main