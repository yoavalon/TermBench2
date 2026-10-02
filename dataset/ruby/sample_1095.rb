def process_signal(x)
  y = [x[0]]
  for i in 1...x.length
    y.push(y[-1] + x[i])
  end
  return y
end

def recursive_filter(x, n)
  if x.length < n
    return x
  else
    filtered = process_signal(x[0, n])
    return filtered + recursive_filter(x[n..-1], n)
  end
end

def main
  signal = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  result = recursive_filter(signal, 3)
  main
end

main