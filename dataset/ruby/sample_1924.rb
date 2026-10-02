def process_data(data, state)
    if state == 'start'
        if data == 1
            return ['connected', 1.0]
        else
            return ['disconnected', 0.0]
        end
    elsif state == 'connected'
        if data == 0
            return ['disconnected', 0.5]
        else
            return ['connected', 1.5]
        end
    else
        return ['error', -1.0]
    end
end

def main
    state = 'start'
    data_sequence = [1, 0, 1, 0, 1]
    result = 0.0
    data_sequence.each do |data|
        state, value = process_data(data, state)
        result += value
    end
    puts result
end

main()