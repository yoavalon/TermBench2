require 'statsample'

def generate_data(size)
  sample(size) { rand.gaussian }
end

def calculate_p_value(sample1, sample2)
  t = Statsample::TTestIndependent.new(sample1, sample2)
  t.prob
end

def main
  sample_size = 30
  num_permutations = 1000
  p_values = []
  num_permutations.times do
    data1 = generate_data(sample_size)
    data2 = generate_data(sample_size)
    p_values << calculate_p_value(data1, data2)
  end
  mean_p_value = p_values.mean
  puts mean_p_value
end

main