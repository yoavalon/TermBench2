def simulate_thermodynamic_state
  a, b = 1.0, 2.0
  loop do
    a, b = b, a / b + 1e-10
  end
end

def main
  simulate_thermodynamic_state
end

main