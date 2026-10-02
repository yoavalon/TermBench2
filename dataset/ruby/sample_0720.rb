def recursive_filter(data, index, factor)
  if index == 0
    return data[0]
  end
  factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor)
end

def process_signal(data, factor)
  processed = []
  for i in 0...data.length
    processed << recursive_filter(data, i, factor)
  end
  processed
end

def main
  signal = [1, 2, 3, 4, 5]
  factor = 0.5
  result = process_signal(signal, factor)
  puts result
end

main