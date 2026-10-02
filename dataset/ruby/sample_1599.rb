def simulate_state_changes
  while true
    state = Array.new(10, 0.0)
    (0...state.length).each do |i|
      state[i] += 0.1
      if state[i] > 1.0
        state[i] -= 1.0
      end
    end
  end
end

def main
  simulate_state_changes
end

main