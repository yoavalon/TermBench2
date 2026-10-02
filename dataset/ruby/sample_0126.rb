def process_connection(state, data)
    if state == 'init'
        if data == 'connect'
            return 'connected'
        end
    elsif state == 'connected'
        if data == 'data'
            return 'processing'
        elsif data == 'disconnect'
            return 'disconnected'
        end
    elsif state == 'processing'
        if data == 'complete'
            return 'connected'
        elsif data == 'disconnect'
            return 'disconnected'
        end
    elsif state == 'disconnected'
        if data == 'connect'
            return 'connected'
        end
    end
    return state
end

def main()
    states = ['init', 'connected', 'processing', 'disconnected']
    data_sequence = ['connect', 'data', 'complete', 'disconnect', 'connect']
    current_state = 'init'
    data_sequence.each do |data|
        current_state = process_connection(current_state, data)
        if !states.include?(current_state)
            break
        end
    end
end

main()