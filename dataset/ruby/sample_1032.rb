def state_machine(state)
    if state == 'open'
        return 'connected'
    elsif state == 'connected'
        return 'transmitting'
    elsif state == 'transmitting'
        return 'closed'
    elsif state == 'closed'
        return 'open'
    end
end

def process(state)
    new_state = state_machine(state)
    process(new_state)
end

def main
    initial_state = 'open'
    process(initial_state)
end

main()