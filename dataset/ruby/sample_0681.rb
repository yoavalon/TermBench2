def process_signal(data, index, threshold)
  if index >= data.length
    return data
  end
  if data[index] > threshold
    data[index] = 0
  end
  return process_signal(data, index + 1, threshold)
end

data = [10, 20, 30, 40, 50]
threshold = 25
processed_data = process_signal(data, 0, threshold)
puts processed_data