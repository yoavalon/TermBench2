def process_signal(data, factor)
  result = []
  for i in 0...data.length
    value = data[i] * factor
    result.push(value.round(5))
  end
  return result
end

def main
  signal = [0.123456, 0.789012, 0.345678]
  factor = 1.2345
  processed = process_signal(signal, factor)
  puts processed
end

main