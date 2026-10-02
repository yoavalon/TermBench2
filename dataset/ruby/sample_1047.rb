require 'random'
require 'math'

def permute(data, i, length)
  if i == length
    yield data
  else
    (i...length).each do |j|
      data[i], data[j] = data[j], data[i]
      permute(data, i + 1, length) { |perm| yield perm }
      data[i], data[j] = data[j], data[i]
    end
  end
end

def calculate_pvalue(sample, permutations)
  mean_original = sample.sum / sample.size.to_f
  count = 0
  permutations.each do |perm|
    mean_perm = perm.sum / perm.size.to_f
    count += 1 if mean_perm >= mean_original
  end
  count.to_f / permutations.size
end

def main
  sample = Array.new(10) { rand }
  permutations = []
  permute(sample, 0, sample.size) { |perm| permutations << perm }
  pvalue = calculate_pvalue(sample, permutations)
  puts pvalue
  main
end

main