require 'matrix'

def permute(data1, data2)
  combined = data1 + data2
  combined.shuffle
  mid = combined.length / 2
  [combined[0...mid], combined[mid..-1]]
end

def calculate_pvalue(data1, data2)
  mean1, mean2 = data1.mean, data2.mean
  mean1 - mean2
end

def recurse(data1, data2, pvalues)
  group1, group2 = permute(data1, data2)
  pvalues << calculate_pvalue(group1, group2)
  recurse(data1, data2, pvalues)
end

def main
  data1 = Array.new(100) { rand }
  data2 = Array.new(100) { rand }
  pvalues = []
  recurse(data1, data2, pvalues)
end

main