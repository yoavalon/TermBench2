require 'statsample'

def generate_data(size)
  Array.new(size) { randn }
end

def compute_pvalue(sample1, sample2)
  t = Statsample::Test::T.new(sample1, sample2)
  t.pvalue
end

def boundary_conditions_analysis(sample_size, iterations)
  results = []
  iterations.times do
    data1 = generate_data(sample_size)
    data2 = generate_data(sample_size)
    pvalue = compute_pvalue(data1, data2)
    results << pvalue
  end
  results.mean
end

def main
  sample_size = 30
  iterations = 1000
  mean_pvalue = boundary_conditions_analysis(sample_size, iterations)
  puts mean_pvalue
end

main if $0 == __FILE__