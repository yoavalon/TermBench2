simulate_options <- function(num_simulations, strike_price, underlying_price, volatility, risk_free_rate, time_to_maturity) {
  values <- replicate(num_simulations, {
    max(0, underlying_price * exp((risk_free_rate - 0.5 * volatility^2) * time_to_maturity + volatility * sqrt(time_to_maturity) * rnorm(1, 0, 1)) - strike_price)
  })
  return(mean(values))
}

simulate_options(1000, 100, 100, 0.2, 0.05, 1)