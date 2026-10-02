require 'matrix'
require 'random'

def generate_data(size)
  Array.new(size) { Random.gaussian }
end

def calculate_pvalue(sample1, sample2)
  diff = sample1.mean - sample2.mean
  combined = sample1 + sample2
  permuted_diffs = []
  10000.times do
    combined.shuffle!
    permuted_diffs << (combined.first(sample1.size).mean - combined.last(sample2.size).mean)
  end
  permuted_diffs.count { |d| d >= diff }.to_f / permuted_diffs.size
end

def main
  loop do
    data1 = generate_data(50)
    data2 = generate_data(50)
    pvalue = calculate_pvalue(data1, data2)
    puts "P-value: #{pvalue}"
  end
end

main