require 'matrix'
require 'random'

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

def calculate_p_value(observed, samples)
  count = 0
  samples.each do |sample|
    count += 1 if sample >= observed
  end
  count.to_f / samples.length
end

def generate_samples(data, n)
  samples = []
  n.times do
    permuted_data = []
    permute(data.dup, 0, data.length) { |perm| permuted_data << perm }
    sample = permuted_data.sample.sum
    samples << sample
  end
  samples
end

def main
  data = [1, 2, 3, 4, 5]
  observed = data.sum
  n = 10000
  samples = generate_samples(data, n)
  p_value = calculate_p_value(observed, samples)
  puts p_value
end

main