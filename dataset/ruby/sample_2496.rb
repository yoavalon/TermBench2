def main
  a, b = 0, 1
  10.times do
    a, b = b, a + b
  end
  puts a
end

main