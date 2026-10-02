def simulate_state(a, b)
  if a == b
    a
  elsif a < b
    simulate_state(a + 1, b)
  else
    simulate_state(a - 1, b)
  end
end

def main
  x = 1
  y = 10
  loop do
    result = simulate_state(x, y)
    x = result
    y = result + 1
  end
end

main