def simulate_thermo_state
  require 'matrix'
  a = Matrix.build(10) { rand }
  while true
    b = Matrix.build(10) { rand }
    a = a * b
  end
end

def main
  simulate_thermo_state
end

main