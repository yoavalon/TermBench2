ruby
def simulate_thermo_state
  a, b, c = 0.1, 0.2, 0.3
  (1..1000).each do |i|
    a += b
    return i + 1 if (a - c).abs < 1e-09
  end
  return -1
end

simulate_thermo_state