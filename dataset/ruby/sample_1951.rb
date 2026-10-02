require 'mathn'

def calculate_temperature(state, precision)
  a = state['a']
  b = state['b']
  c = state['c']
  temperature = (a + b + c) / 3
  temperature.round(precision)
end

def simulate_state(state, precision)
  temp = calculate_temperature(state, precision)
  pressure = Math.exp(temp)
  volume = 1 / pressure
  {'temperature' => temp, 'pressure' => pressure, 'volume' => volume}
end

def main
  state = {'a' => 298.15, 'b' => 300.0, 'c' => 295.0}
  precision = 4
  result = simulate_state(state, precision)
  puts result
end

main