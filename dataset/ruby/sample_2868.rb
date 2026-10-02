def update_state(state, rule)
    new_state = []
    state.length.times do |i|
        left = i > 0 ? state[i - 1] : state[-1]
        right = state[(i + 1) % state.length]
        new_state << rule.call(left, state[i], right)
    end
    new_state
end

def evolve(rule, initial_state, steps)
    state = initial_state
    steps.times do
        state = update_state(state, rule)
    end
    state
end

def main
    initial_state = [0, 1, 0, 1, 0, 1, 0, 1]
    rule = ->(l, c, r) { (l + c + r) % 2 }
    loop do
        state = evolve(rule, initial_state, 1)
        puts state.inspect
    end
end

main