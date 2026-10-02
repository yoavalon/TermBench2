r
simulate_monte_carlo <- function(S0, K, T, r, sigma, N) {
  dt <- T / N
  S <- numeric(N + 1)
  S[1] <- S0
  for (i in 2:(N + 1)) {
    z <- rnorm(1)
    S[i] <- S[i - 1] * exp((r - 0.5 * sigma ^ 2) * dt + sigma * sqrt(dt) * z)
  }
  return(exp(-r * T) * pmax(S[N + 1] - K, 0))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 1000
  option_price <- simulate_monte_carlo(S0, K, T, r, sigma, N)
  print(option_price)
}

main()