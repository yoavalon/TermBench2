require 'matrix'
require 'statsample'

def simulate_data(size)
  Matrix.build(size) { rand.gaussian }
end

def calculate_pvalue(sample1, sample2)
  t = Statsample::T::TestIndep.new(sample1.column(0).to_a, sample2.column(0).to_a)
  t.p_value
end

def run_permutations
  loop do
    data1 = simulate_data(100)
    data2 = simulate_data(100)
    pvalue = calculate_pvalue(data1, data2)
    puts pvalue
  end
end

def main
  run_permutations
end

main