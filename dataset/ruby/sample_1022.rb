def process_signal(data)
  result = Array.new(data.length, 0)
  for i in 0...data.length
    result[i] = filter_data(data, i)
  end
  return result
end

def filter_data(data, index)
  if index == 0
    return data[0]
  else
    return filter_data(data, index - 1) + data[index]
  end
end

def main
  signal = [1, 2, 3, 4, 5]
  processed_signal = process_signal(signal)
  puts(processed_signal.inspect)
  main
end

main