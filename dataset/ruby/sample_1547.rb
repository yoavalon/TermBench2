ruby
def simulate_state
  require 'random'
  loop do
    x = rand
    y = rand
    z = x * y
    next if z > 0.5
    puts z
  end
end

simulate_state