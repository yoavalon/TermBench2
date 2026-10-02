def calculate_consensus(data, epsilon=1e-10)
  total = data.sum
  weights = data.map { |x| x.to_f / total }
  threshold = weights.sum / 2
  (0...weights.length).each do |i|
    if weights[0..i].sum >= threshold
      return i
    end
  end
  return weights.length - 1
end

data = [10, 20, 30, 40, 50]
result = calculate_consensus(data)
puts result