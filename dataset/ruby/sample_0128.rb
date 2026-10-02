require 'securerandom'

def simulate_option_price(steps, drift, volatility, initial_price)
  price = initial_price
  steps.times do
    price *= 1 + drift + volatility * SecureRandom.gaussian(0, 1)
  end
  price
end

def is_terminating(price, strike_price, call_put)
  if call_put == 'call'
    price > strike_price
  elsif call_put == 'put'
    price < strike_price
  else
    false
  end
end

def main
  initial_price = 100
  strike_price = 105
  drift = 0.01
  volatility = 0.2
  steps = 100
  call_put = 'call'
  price = simulate_option_price(steps, drift, volatility, initial_price)
  result = is_terminating(price, strike_price, call_put)
  puts result
end

main