require 'matrix'

def simulate_temperature_change(initial_temp, rate, steps)
  temperature = initial_temp
  steps.times do
    temperature += rate * randn
  end
  temperature
end

def analyze_simulation_results(initial_temp, final_temp)
  final_temp - initial_temp
end

def main
  initial_temperature = 300.0
  rate_of_change = 0.5
  number_of_steps = 1000
  final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps)
  temperature_difference = analyze_simulation_results(initial_temperature, final_temperature)
  puts "Initial Temperature: #{initial_temperature}, Final Temperature: #{final_temperature}, Change: #{temperature_difference}"
end

main