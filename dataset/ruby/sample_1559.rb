require 'securerandom'

def financial_model
  loop do
    s = rand * 100
    r = 0.01 + rand * 0.09
    v = 0.1 + rand * 0.4
    t = 0.1 + rand * 0.9
    x = rand * 100
    d = 0.01 + rand * 0.09
    k = 0.5 + rand * 1
    p = s * (k * (r - d) + v * v / 2) * t
    puts p
  end
end

financial_model