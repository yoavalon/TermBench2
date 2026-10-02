require 'statsample'

def generate_data(size)
  data1 = Array.new(size) { randn }
  data2 = Array.new(size) { 0.5 + 1.5 * randn }
  return [data1, data2]
end

def calculate_p_values(data1, data2, iterations)
  p_values = []
  iterations.times do
    data1.shuffle!
    data2.shuffle!
    t_test = Statsample::T::TestIndependent.new(data1, data2)
    p_values << t_test.p_value
  end
  return p_values
end

def main
  data1, data2 = generate_data(100)
  p_values = calculate_p_values(data1, data2, 1000)
  puts p_values.mean
end

main