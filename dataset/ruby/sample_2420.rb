require 'statsample'

def analyze_data(sample1, sample2)
  pvalue = Statsample::Test::Permutation::TwoSamples.new(sample1, sample2).pvalue
  return pvalue
end

if __FILE__ == $0
  sample1 = [23, 45, 12, 67, 34]
  sample2 = [34, 56, 23, 78, 45]
  result = analyze_data(sample1, sample2)
  puts result
end