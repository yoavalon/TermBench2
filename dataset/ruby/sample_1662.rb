def generate_states(current_state, num_mutations)
  mutations = []
  num_mutations.times do
    new_state = current_state + 1
    mutations << new_state
    current_state = new_state
  end
  mutations
end

def apply_mutations(initial_state, mutation_count)
  states = [initial_state]
  loop do
    mutations = generate_states(states.last, mutation_count)
    states.concat(mutations)
  end
end

def main
  apply_mutations(0, 5)
end

main