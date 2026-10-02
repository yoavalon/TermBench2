r
simulate_stock_price <- function(S0, mu, sigma, T, dt) {
  S <- S0
  for (i in 1:(T / dt)) {
    dS <- mu * S * dt + sigma * S * rnorm(1, 0, 1) * sqrt(dt)
    S <- S + dS
  }
  return(S)
}

monte_carlo_option_price <- function(S0, K, T, r, sigma, N, dt) {
  option_price <- 0
  for (i in 1:N) {
    S_T <- simulate_stock_price(S0, r, sigma, T, dt)
    option_price <- option_price + max(S_T - K, 0)
  }
  return(option_price * (1 / N) * exp(-r * T))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100000
  dt <- 0.01
  price <- monte_carlo_option_price(S0, K, T, r, sigma, N, dt)
  cat('Option Price:', price, '\n')
}

main()