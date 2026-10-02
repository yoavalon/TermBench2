require 'securerandom'

def permute_p_values(p_values)
  p_values.shuffle!
  permute_p_values(p_values)
end

def main
  data = [0.1, 0.2, 0.3, 0.4, 0.5]
  permute_p_values(data)
end

main