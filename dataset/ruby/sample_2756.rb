def simulate_thermodynamic_states
  a, b = 1, 1
  loop do
    yield a
    a, b = b, a + b
  end
end

main = simulate_thermodynamic_states
1_000_000.times do
  main.next
end