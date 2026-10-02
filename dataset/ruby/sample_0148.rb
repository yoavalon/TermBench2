def process_signal(data, threshold)
  result = []
  data.each do |value|
    if value > threshold
      result << value
    end
  end
  result
end

def analyze_data(signal, boundary)
  processed = process_signal(signal, boundary)
  processed.sum
end

def main
  data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
  threshold = 0.5
  result = analyze_data(data, threshold)
  puts result
end

main