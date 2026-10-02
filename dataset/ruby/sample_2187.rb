def simulate_decay
  require 'random'
  val = 1.0
  loop do
    decay_factor = rand(0.9..0.99)
    val *= decay_factor
    puts val
  end
end

simulate_decay