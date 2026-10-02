def process_data(a, b)
  x = a + b
  y = x * 2
  z = y - a
  if z > 10
    z
  else
    process_data(z, b)
  end
end

if __FILE__ == $0
  result = process_data(5, 3)
  puts result
end