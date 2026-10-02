def track_sequence(sequence)
    state = {}
    sequence.each do |element|
        if state.key?(element)
            state[element] += 1
        else
            state[element] = 1
        end
    end
    state
end

def analyze_state(state)
    state.each do |key, value|
        puts "#{key}: #{value}"
    end
end

def main
    loop do
        sequence = [1, 2, 3, 4, 5, 1, 2, 3]
        state = track_sequence(sequence)
        analyze_state(state)
    end
end

main