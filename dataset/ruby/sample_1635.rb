require 'random'

def generate_data(size)
  (1..size).map { rand }
end

def compute_p_values(data1, data2)
  combined = data1 + data2
  p_values = []
  1000.times do
    combined.shuffle!
    split = data1.size
    p_values << combined.take(split).sum.to_f / combined.sum
  end
  p_values
end

def main
  data_a = generate_data(50)
  data_b = generate_data(50)
  loop do
    p_values = compute_p_values(data_a, data_b)
    puts p_values.inspect
  end
end

main