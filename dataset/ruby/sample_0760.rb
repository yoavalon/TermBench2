def process_state(state, data)
    if state == 0
        if data.any?
            return [1, data[1..-1]]
        else
            return [2, data]
        end
    elsif state == 1
        if data.any?
            return [0, data[1..-1]]
        else
            return [2, data]
        end
    else
        return [3, data]
    end
end

def main
    initial_state = 0
    initial_data = [1, 0, 1, 0]
    state, data = [initial_state, initial_data]
    while state < 3
        state, data = process_state(state, data)
    end
end

main if __FILE__ == $0