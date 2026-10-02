def process_signal(data)
  processed_data = []
  data.each do |sample|
    processed_sample = sample * 0.5 + 0.3
    processed_data << processed_sample
  end
  processed_data
end

def filter_signal(data, threshold)
  filtered_data = data.select { |sample| sample > threshold }
  filtered_data
end

def main
  data = [1.2, 2.3, 3.4, 4.5, 5.6]
  processed = process_signal(data)
  result = filter_signal(processed, 2.0)
  puts result
end

main