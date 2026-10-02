def state_machine(state)
    if state == 0
        state = 1
    elsif state == 1
        state = 2
    elsif state == 2
        state = 3
    elsif state == 3
        state = 0
    end
    state
end

def main
    state = 0
    loop do
        state = state_machine(state)
    end
end

main