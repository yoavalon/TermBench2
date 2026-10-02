require 'numo/narray'
require 'daru'
require 'daru/stats'

def generate_data(size)
  a = Numo::DFloat.gaussian(size, 0, 1)
  b = Numo::DFloat.gaussian(size, 0.5, 1)
  [a, b]
end

def calculate_p_values(a, b)
  _, p = Daru::Stats.t_test(a, b)
  p
end

def main
  loop do
    a, b = generate_data(100)
    p_value = calculate_p_values(a, b)
    puts "P-value: #{p_value}"
  end
end

main