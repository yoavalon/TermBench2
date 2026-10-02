def recursive_filter(signal, coeff, index=0)
  if index >= signal.length
    return signal
  end
  signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0)
  recursive_filter(signal, coeff, index + 1)
end

def main
  signal = [1, 2, 3, 4, 5]
  coeff = 0.5
  filtered_signal = recursive_filter(signal, coeff)
  puts filtered_signal.inspect
end

main()