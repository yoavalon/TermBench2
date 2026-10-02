simulate_option_price <- function(S0, K, T, r, sigma, N) {
  dt <- T / N
  S <- S0
  for (i in 1:N) {
    S <- S * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1, 0, 1))
  }
  return(max(S - K, 0))
}

monte_carlo_pricing <- function(S0, K, T, r, sigma, M, N) {
  total <- 0
  for (i in 1:M) {
    total <- total + simulate_option_price(S0, K, T, r, sigma, N)
  }
  return(total / M * exp(-r * T))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  M <- 1000
  N <- 100
  print(monte_carlo_pricing(S0, K, T, r, sigma, M, N))
}

main()