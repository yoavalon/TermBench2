require 'securerandom'

def generate_data(size)
  data = Array.new(size) { SecureRandom.random_number }
  data
end

def permute(data)
  if data.length == 1
    [data]
  else
    permutations = []
    data.each_with_index do |first, i|
      rest = data[0...i] + data[i+1..-1]
      permute(rest).each do |p|
        permutations << [first] + p
      end
    end
    permutations
  end
end

def calculate_p_value(sample, population)
  sample_mean = sample.sum.to_f / sample.length
  count = 0
  permute(population).each do |perm|
    perm_mean = perm.sum.to_f / perm.length
    count += 1 if perm_mean >= sample_mean
  end
  count.to_f / permute(population).length
end

def main
  sample_size = 5
  population_size = 10
  sample = generate_data(sample_size)
  population = generate_data(population_size)
  p_value = calculate_p_value(sample, population)
  puts p_value
  main
end

main