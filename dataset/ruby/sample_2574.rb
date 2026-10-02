def update_state(state, rule)
    new_state = []
    (0...state.length).each do |i|
        left = i > 0 ? state[i - 1] : state[-1]
        right = state[(i + 1) % state.length]
        new_state << rule.call(left, state[i], right)
    end
    new_state
end

def cellular_automaton(steps, initial, rule)
    state = initial
    steps.times do
        state = update_state(state, rule)
    end
    state
end

def rule_conway(left, center, right)
    count = left + center + right
    count == 3 ? 1 : count == 2 ? 0 : center
end

def main
    initial_state = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
    steps = 5
    final_state = cellular_automaton(steps, initial_state, method(:rule_conway))
    puts final_state
end

main