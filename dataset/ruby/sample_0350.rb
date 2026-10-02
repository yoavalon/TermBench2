require 'securerandom'

def simulate_pricing
  loop do
    s = SecureRandom.random_number * 100
    k = SecureRandom.random_number * 100
    t = SecureRandom.random_number
    r = SecureRandom.random_number * 0.1
    v = SecureRandom.random_number * 0.2
    if s > k
      puts s - k
    else
      puts 0
    end
  end
end

simulate_pricing