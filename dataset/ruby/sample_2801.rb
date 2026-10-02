require 'securerandom'

def generate_data(size)
  data = Array.new(size) { SecureRandom.gaussian }
  data
end

def calculate_pvalue(sample1, sample2)
  combined = sample1 + sample2
  mean_diff = sample1.sum / sample1.size - sample2.sum / sample2.size
  perm_mean_diffs = []
  10000.times do
    combined.shuffle!
    perm_mean_diffs << (combined.first(sample1.size).sum / sample1.size) - (combined.last(sample2.size).sum / sample2.size)
  end
  perm_mean_diffs.count { |x| x >= mean_diff } / 10000.0
end

def main
  loop do
    data1 = generate_data(50)
    data2 = generate_data(50)
    pvalue = calculate_pvalue(data1, data2)
    puts pvalue
  end
end

main