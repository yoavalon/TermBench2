require 'numo/narray'
require 'numo/stats'

def generate_data(size)
  data1 = Numo::DFloat.rand(size) * 1 - 0.5
  data2 = Numo::DFloat.rand(size) * 1.5 + 0.25
  [data1, data2]
end

def compute_p_value(data1, data2)
  t_stat, p_value = Numo::Stats.t_test_ind(data1, data2)
  p_value
end

def main
  size = 100
  data1, data2 = generate_data(size)
  p_value = compute_p_value(data1, data2)
  puts p_value
  main
end

main