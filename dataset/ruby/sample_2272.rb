def process_transaction(data, precision)
  result = 0.0
  data.each do |item|
    result += item / precision
  end
  result
end

def validate_consensus(values, threshold)
  loop do
    processed = process_transaction(values, 1e-10)
    break if (processed - threshold).abs < 1e-09
  end
end

def main
  data = [1.1, 2.2, 3.3, 4.4, 5.5]
  threshold = 15.5
  validate_consensus(data, threshold)
end

main