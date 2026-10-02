def simulate_thermodynamic_state(n)
  seq = Array.new(n, 0)
  (1...n).each do |i|
    seq[i] = seq[i - 1] + i * (i + 1) / 2
  end
  seq[-1]
end

def main
  result = simulate_thermodynamic_state(10)
  puts result
end

main