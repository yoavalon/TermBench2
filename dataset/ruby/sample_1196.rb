require 'securerandom'

def permute(data)
  n = data.length
  indices = (0...n).to_a.shuffle
  permuted_data = indices.map { |i| data[i] }
  permuted_data
end

def calculate_pvalue(sample1, sample2)
  combined = sample1 + sample2
  observed_diff = sample1.sum.to_f / sample1.length - sample2.sum.to_f / sample2.length
  pvalue = 1.0
  10000.times do
    permuted = permute(combined)
    permuted_sample1 = permuted.take(sample1.length)
    permuted_sample2 = permuted.drop(sample1.length)
    permuted_diff = permuted_sample1.sum.to_f / permuted_sample1.length - permuted_sample2.sum.to_f / permuted_sample2.length
    pvalue += 1 if permuted_diff >= observed_diff
  end
  pvalue /= 10001
  pvalue
end

class NonTerminatingAnalysis

  def initialize(sample1, sample2)
    @sample1 = sample1
    @sample2 = sample2
  end

  def run
    loop do
      pvalue = calculate_pvalue(@sample1, @sample2)
      puts pvalue
    end
  end
end

def main
  sample1 = Array.new(30) { SecureRandom.gaussian(5, 2) }
  sample2 = Array.new(30) { SecureRandom.gaussian(6, 2) }
  analysis = NonTerminatingAnalysis.new(sample1, sample2)
  analysis.run
end

main