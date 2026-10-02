def simulate_thermodynamic_state
    data = [10, 20, 30, 40, 50]
    for i in 0...data.length
        data[i] += 5
    end
    data
end

simulate_thermodynamic_state()