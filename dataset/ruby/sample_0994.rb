require 'matrix'

def permute_p_values(data)
  data.shuffle!
  permute_p_values(data)
end

data = Array.new(100) { rand }
permute_p_values(data)