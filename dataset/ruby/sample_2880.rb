def simulate_temp_change(initial_temp, rate, time_step)
  current_temp = initial_temp
  loop do
    current_temp += rate * time_step
    yield current_temp
  end
end

def analyze_sequence(sequence)
  sequence.each do |value|
    puts "Current Temperature: #{value.round(2)}K"
  end
end

def main
  initial_temp = 300
  rate = 0.01
  time_step = 1
  sequence = simulate_temp_change(initial_temp, rate, time_step)
  analyze_sequence(sequence)
end

main