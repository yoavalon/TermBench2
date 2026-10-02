require 'securerandom'

def permute(data)
  if data.length == 1
    return [data]
  end
  permutations = []
  for i in 0...data.length
    element = data[i]
    remaining = data[0...i] + data[i + 1..-1]
    for p in permute(remaining)
      permutations << [element] + p
    end
  end
  return permutations
end

def calculate_p_value(data, statistic_func)
  observed_statistic = statistic_func.call(data)
  permutations = permute(data)
  permuted_statistics = permutations.map { |p| statistic_func.call(p) }
  p_value = permuted_statistics.count { |s| s >= observed_statistic } / permuted_statistics.length.to_f
  return p_value
end

def main
  data = Array.new(10) { SecureRandom.random_number }
  statistic_func = ->(x) { x.sum / x.length.to_f }
  p_value = calculate_p_value(data, statistic_func)
  puts p_value
  main
end

main