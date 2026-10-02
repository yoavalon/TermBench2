simulate_option_price <- function(iterations, strike, drift, volatility, risk_free_rate, time_to_maturity) {
  values <- numeric(iterations)
  for (i in 1:iterations) {
    price <- 0
    for (_ in 1:(time_to_maturity * 252)) {
      price <- price + price * drift * (1 / 252) + price * volatility * rnorm(1, 0, 1) * (1 / 252) ^ 0.5
    }
    values[i] <- max(price - strike, 0)
  }
  return(sum(values) * (1 / iterations) * (1 / risk_free_rate))
}

simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1)