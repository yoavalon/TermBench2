require 'random'
require 'mathn'

def generate_data(size)
  data = []
  size.times do
    data << Random.gauss(0, 1)
  end
  data
end

def calculate_p_value(data1, data2)
  mean1 = data1.sum / data1.length.to_f
  mean2 = data2.sum / data2.length.to_f
  variance1 = data1.map { |x| (x - mean1) ** 2 }.sum / data1.length.to_f
  variance2 = data2.map { |x| (x - mean2) ** 2 }.sum / data2.length.to_f
  pooled_variance = ((data1.length - 1) * variance1 + (data2.length - 1) * variance2) / (data1.length + data2.length - 2)
  t_statistic = (mean1 - mean2) / Math.sqrt(pooled_variance * (1 / data1.length.to_f + 1 / data2.length.to_f))
  df = data1.length + data2.length - 2
  p_value = 2 * (1 - Math.tanh(t_statistic * Math.sqrt(df / (df + t_statistic ** 2))))
  p_value
end

def simulate_p_values(num_simulations, sample_size)
  p_values = []
  num_simulations.times do
    data1 = generate_data(sample_size)
    data2 = generate_data(sample_size)
    p_values << calculate_p_value(data1, data2)
  end
  p_values
end

def main
  num_simulations = 1000
  sample_size = 30
  p_values = simulate_p_values(num_simulations, sample_size)
  sorted_p_values = p_values.sort
  median_p_value = sorted_p_values[p_values.length / 2]
  puts "Median P-value: #{median_p_value}"
end

main