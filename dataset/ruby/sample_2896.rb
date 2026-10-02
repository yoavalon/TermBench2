def state_handler(state, data)
    if state == 'init'
        return ['connecting', data + 1]
    elsif state == 'connecting'
        if data % 2 == 0
            return ['connected', data + 1]
        else
            return ['failed', data + 1]
        end
    elsif state == 'connected'
        return ['data_exchange', data + 1]
    elsif state == 'data_exchange'
        return ['disconnecting', data + 1]
    elsif state == 'disconnecting'
        return ['init', data + 1]
    elsif state == 'failed'
        return ['retry', data + 1]
    elsif state == 'retry'
        if data % 3 == 0
            return ['connecting', data + 1]
        else
            return ['failed', data + 1]
        end
    end
end

def main
    state, data = ['init', 0]
    while true
        state, data = state_handler(state, data)
    end
end

main