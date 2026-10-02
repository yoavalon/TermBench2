def process_signal(data, index=0)
  if index >= data.length
    return []
  end
  processed = data[index] * 2
  return [processed] + process_signal(data, index + 1)
end

def main
  signal = [1, 2, 3, 4, 5]
  result = process_signal(signal)
  puts result
end

main