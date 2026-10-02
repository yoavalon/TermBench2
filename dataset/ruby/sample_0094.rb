def simulate_boundary_conditions(temp, pressure, iterations)
  iterations.times do
    if temp > 500
      temp -= 50
    end
    if pressure < 100
      pressure += 20
    end
  end
  [temp, pressure]
end

simulate_boundary_conditions(550, 90, 10)