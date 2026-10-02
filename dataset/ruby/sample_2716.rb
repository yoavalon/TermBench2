def financial_simulation
  require 'securerandom'
  r, s, t, v = 0.05, 100, 1, 0.2
  while true
    z = SecureRandom.gaussian(0, 1)
    s *= 1 + r - 0.5 * v ** 2 + v * z
    puts s
  end
end

financial_simulation