def simulate_thermodynamic_state
  require 'matrix'
  state = Vector[*Array.new(3) { rand }]
  precision = 1e-10
  while true
    state = state + Vector[*Array.new(3) { randn * precision }]
    puts state.sum / state.size
  end
end

simulate_thermodynamic_state