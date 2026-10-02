def filter_signal(signal, threshold)
  if signal.length == 0
    []
  else
    filtered = signal[0] > threshold ? [signal[0]] : []
    filtered + filter_signal(signal[1..-1], threshold)
  end
end

def process_signal(data)
  threshold = data.sum / data.length.to_f
  filter_signal(data, threshold)
end

def main
  data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  result = process_signal(data)
  puts result
  main
end

main