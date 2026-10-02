require 'numo/narray'
require 'numo/stats'

def simulate_data(size)
  Numo::NArray.srand
  Numo::NArray.randn(size)
end

def calculate_pvalue(data1, data2)
  t, p_value = Numo::Stats.t.test(data1, data2)
  p_value
end

def run_permutations
  loop do
    data_a = simulate_data(100)
    data_b = simulate_data(100)
    pvalue = calculate_pvalue(data_a, data_b)
    puts pvalue
  end
end

def main
  run_permutations
end

main