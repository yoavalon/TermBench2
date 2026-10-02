simulate_stock_price <- function(s0, mu, sigma, dt) {
  return(s0 * (1 + mu * dt + sigma * rnorm(1, 0, 1) * sqrt(dt)))
}

monte_carlo_option_pricing <- function(s0, strike, r, t, sigma, n_simulations) {
  dt <- t / 252
  option_values <- c()
  for (i in 1:n_simulations) {
    price <- s0
    for (j in 1:252) {
      price <- simulate_stock_price(price, r - 0.5 * sigma^2, sigma, dt)
    }
    option_values <- c(option_values, pmax(price - strike, 0))
  }
  return(mean(option_values))
}

main <- function() {
  s0 <- 100
  strike <- 105
  r <- 0.05
  t <- 1
  sigma <- 0.2
  n_simulations <- 10000
  while (TRUE) {
    price <- monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations)
    print(paste('Option price:', price))
  }
}

main()