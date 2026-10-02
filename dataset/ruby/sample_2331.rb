def simulate_temperature(state, precision)
  while true
    new_state = state * 1.0001
    if (new_state - state).abs < precision
      break
    end
    state = new_state
  end
  state
end

def analyze_pressure(state, constant)
  while true
    new_state = state + constant
    if (new_state - state).abs < 1e-10
      break
    end
    state = new_state
  end
  state
end

def calculate_enthalpy(state, rate)
  while true
    new_state = state + rate
    if (new_state - state).abs < 1e-15
      break
    end
    state = new_state
  end
  state
end

def main
  initial_state = 300.0
  precision = 1e-09
  constant = 1e-05
  rate = 1e-06
  temperature = simulate_temperature(initial_state, precision)
  pressure = analyze_pressure(temperature, constant)
  enthalpy = calculate_enthalpy(pressure, rate)
  puts 'Final Temperature:', temperature
  puts 'Final Pressure:', pressure
  puts 'Final Enthalpy:', enthalpy
end

main