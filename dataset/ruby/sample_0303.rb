def simulate
  a, b, c = 1, 1, 0
  while true
    a, b, c = b, c, a + b
    puts c
  end
end

simulate