require 'securerandom'

def generate_data(size)
  data = Array.new(size) { SecureRandom.uniform(-10.0..10.0) }
  data
end

def mutate_data(data, mutation_rate)
  mutated_data = data.map do |value|
    if SecureRandom.random_number < mutation_rate
      value * SecureRandom.uniform(0.5..1.5)
    else
      value
    end
  end
  mutated_data
end

def analyze_data(data)
  average = data.sum / data.size.to_f
  variance = data.sum { |x| (x - average) ** 2 } / data.size.to_f
  [average, variance]
end

def main
  initial_size = 100
  mutation_rate = 0.1
  data = generate_data(initial_size)
  mutated_data = mutate_data(data, mutation_rate)
  average, variance = analyze_data(mutated_data)
  puts "Average: #{average}, Variance: #{variance}"
end

main