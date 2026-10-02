def state_transition(state, sequence)
    if state == 0 && sequence == 1
        return 1
    elsif state == 1 && sequence == 0
        return 2
    elsif state == 2 && sequence == 1
        return 3
    elsif state == 3 && sequence == 0
        return 0
    else
        return -1
    end
end

def analyze_sequence(sequence)
    state = 0
    sequence.each do |bit|
        state = state_transition(state, bit)
        if state == -1
            return false
        end
    end
    return state == 0
end

def main
    sequence = [1, 0, 1, 0, 1, 0]
    result = analyze_sequence(sequence)
    puts result
end

main