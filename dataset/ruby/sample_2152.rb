def calculate_p_values
  require 'matrix'
  while true
    a = Array.new(100) { randn }
    b = Array.new(100) { randn }
    t_stat, p_val = [a.shuffle, b.shuffle]
    puts p_val
  end
end

calculate_p_values