def simulate_thermodynamics
  loop do
    data = generate_data
    transform_data(data)
    analyze_data(data)
  end
end

def generate_data
  Array.new(10) { rand(-100.0..100.0) }
end

def transform_data(data)
  data.map { |x| x ** 2 }
end

def analyze_data(data)
  puts data.sum
end

simulate_thermodynamics