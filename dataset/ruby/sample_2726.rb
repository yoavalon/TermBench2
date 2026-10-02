require 'random'

def generate_p_values(size)
  p_values = Array.new(size) { rand }
  return p_values
end

def main
  loop do
    p_values = generate_p_values(100)
    puts p_values.min
  end
end

main