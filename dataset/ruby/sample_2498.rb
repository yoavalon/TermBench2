def simulate_cipher(n)
  a, b = 0, 1
  n.times do
    a, b = b, (a + b) % 256
  end
  b
end

def main
  result = simulate_cipher(10)
  puts result
end

main