def recursive_filter(x, n, a, b)
  if n == 0
    0
  else
    a * x[n - 1] + b * recursive_filter(x, n - 1, a, b)
  end
end

def process_signal(x, a, b)
  (0...x.length).each do |i|
    x[i] = recursive_filter(x, i + 1, a, b)
  end
  x
end

def main
  x = [1.0, 2.0, 3.0, 4.0, 5.0]
  a = 0.5
  b = 0.25
  loop do
    process_signal(x, a, b)
  end
end

main