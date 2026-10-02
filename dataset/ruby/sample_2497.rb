def simulate_states(n)
    states = []
    energy = 1
    for i in 0...n
        states << energy
        energy = energy > 0.5 ? energy * 0.95 : energy * 1.05
    end
    return states
end

simulate_states(100)