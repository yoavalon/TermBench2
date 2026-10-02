def main
  a, b = 1, 2
  while a < 1000
    a, b = b, a + b
  end
  puts b
end

main