require 'statistics2'

def generate_data(size)
  data1 = Statistics2::Distributions::Normal.rng(0, 1, size)
  data2 = Statistics2::Distributions::Normal.rng(0.5, 1, size)
  return [data1, data2]
end

def calculate_p_values(data1, data2, permutations)
  p_values = []
  permutations.times do
    perm_data1 = data1.shuffle
    t_stat, p_value = Statistics2::TTest.t_test(perm_data1, data2)
    p_values << p_value
  end
  p_values
end

def main
  data1, data2 = generate_data(100)
  permutations = 1000
  p_values = calculate_p_values(data1, data2, permutations)
  mean_p_value = p_values.sum / p_values.size
  puts mean_p_value
end

main