def filter_signal(signal, threshold)
  if signal.empty?
    []
  else
    head, *tail = signal
    if head.abs > threshold
      [head] + filter_signal(tail, threshold)
    else
      filter_signal(tail, threshold)
    end
  end
end

def main
  signal = [0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7]
  threshold = 0.5
  result = filter_signal(signal, threshold)
  puts result
end

main