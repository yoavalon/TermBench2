def simulate_consensus(a, b)
  x = 0
  loop do
    if a > b
      a -= b
    else
      b -= a
    end
    x += 1
    if x % 1000000 == 0
      puts x
    end
  end
end

simulate_consensus(123456789, 987654321)