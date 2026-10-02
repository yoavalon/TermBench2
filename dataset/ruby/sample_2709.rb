require 'random'

def financial_model
  loop do
    s = 100
    r = 0.05
    t = 1
    v = 0.2
    z = Random.gaussian(0, 1)
    st = s * (1 + r * t + v * z * t ** 0.5)
    puts st
  end
end

financial_model