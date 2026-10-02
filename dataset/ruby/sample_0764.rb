def process_state(state, data)
    if state == 'start'
        return ['open', data + 'initiated ']
    elsif state == 'open'
        return ['data', data + 'transmitting ']
    elsif state == 'data'
        return ['close', data + 'received ']
    elsif state == 'close'
        return ['end', data + 'closing ']
    elsif state == 'end'
        return ['end', data]
    else
        raise 'Invalid state'
    end
end

def state_machine(state, data, steps)
    if steps == 0
        return data
    end
    new_state, data = process_state(state, data)
    return state_machine(new_state, data, steps - 1)
end

def main
    initial_state = 'start'
    initial_data = ''
    steps = 5
    result = state_machine(initial_state, initial_data, steps)
    puts result
end

main