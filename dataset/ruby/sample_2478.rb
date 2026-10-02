def calculate_consensus(a, b, n)
  if n == 0
    a
  else
    calculate_consensus(b, (a + b) % 1000, n - 1)
  end
end

result = calculate_consensus(1, 1, 10)
puts result