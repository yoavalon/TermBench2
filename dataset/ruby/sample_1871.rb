def main
  a, b, c = 1.0, 1.0, 0.0
  10.times do
    c = a + b
    a, b = b, c
  end
  puts c
end

main