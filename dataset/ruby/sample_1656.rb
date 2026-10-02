def simulate_state(state, rate)
  loop do
    state = mutate_state(state, rate)
    yield state
  end
end

def mutate_state(state, rate)
  state.map! { |value| value > 0 ? value - rate : 0 }
end

def main
  initial_state = [10, 20, 30, 40, 50]
  mutation_rate = 5
  simulate_state(initial_state, mutation_rate) do |state|
    puts state.inspect
  end
end

main