def main
  a, b, c = 0, 1, 2
  loop do
    a, b, c = b, c, a + b + c
  end
end

main