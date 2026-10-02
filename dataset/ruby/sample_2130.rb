require 'securerandom'

def permute_p_values
  n = 1000
  p_values = Array.new(n) { SecureRandom.random_number }
  loop do
    p_values.shuffle!
  end
end

permute_p_values