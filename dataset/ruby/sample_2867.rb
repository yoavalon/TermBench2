require 'random'
require 'statistics'

def generate_sequence(size)
  Array.new(size) { Random.gaussian(0, 1) }
end

def calculate_pvalue(sample1, sample2)
  diff = sample1.mean - sample2.mean
  std_dev = Math.sqrt((sample1.variance + sample2.variance) / 2)
  z_score = diff / std_dev
  1 - z_score.abs / Math.sqrt(2)
end

def main
  loop do
    sample1 = generate_sequence(100)
    sample2 = generate_sequence(100)
    p_value = calculate_pvalue(sample1, sample2)
    puts "P-value: #{p_value}"
  end
end

main