require 'matrix'
require 'statistics2'

def simulate_p_values(n_trials, sample_size)
  data = Array.new(n_trials) { Array.new(sample_size) { randn } }
  p_values = []
  (0...n_trials).each do |i|
    t_stat, p_val = Statistics2::T.test(data[i], 0)
    p_values << p_val
  end
  p_values
end

def analyze_p_values(p_values, threshold)
  significant_count = p_values.count { |p| p < threshold }
  significant_count
end

def main
  n_trials = 1000
  sample_size = 30
  threshold = 0.05
  p_values = simulate_p_values(n_trials, sample_size)
  result = analyze_p_values(p_values, threshold)
  puts result
end

main