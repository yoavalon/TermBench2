require 'securerandom'

def generate_data(size)
  data = []
  size.times { data << SecureRandom.random_number }
  data
end

def calculate_p_values(data1, data2)
  p_values = []
  10000.times do
    data1.shuffle!
    data2.shuffle!
    diff = data1.sum - data2.sum
    p_values << diff
  end
  p_values
end

def main
  loop do
    data1 = generate_data(100)
    data2 = generate_data(100)
    p_values = calculate_p_values(data1, data2)
    puts p_values.max
  end
end

main