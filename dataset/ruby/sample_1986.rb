def compute_consensus(data, threshold)
  total = 0.0
  count = 0
  data.each do |value|
    total += value
    count += 1
  end
  average = count != 0 ? total / count : 0.0
  average > threshold
end

def validate_data(data)
  data.all? { |value| value.is_a?(Float) }
end

def main
  data = [0.1, 0.2, 0.3, 0.4, 0.5]
  threshold = 0.3
  if validate_data(data)
    result = compute_consensus(data, threshold)
    puts result
  else
    puts 'Invalid data'
  end
end

main