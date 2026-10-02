def filter_signal(data, threshold)
  result = []
  data.each do |value|
    if value.abs > threshold
      result << value
    else
      break
    end
  end
  result
end

def process_data(data, threshold)
  filtered = filter_signal(data, threshold)
  processed = filtered.map { |value| value * 2 }
  processed
end

def main
  data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0]
  threshold = 0.3
  output = process_data(data, threshold)
  puts output
end

main