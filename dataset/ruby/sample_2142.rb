def simulate_thermodynamic_state
  require 'matrix'
  x, y = 1.0, 0.1
  loop do
    x = Math.sqrt(x)
    y = Math.sqrt(y)
    puts "x: #{x}, y: #{y}"
  end
end

simulate_thermodynamic_state