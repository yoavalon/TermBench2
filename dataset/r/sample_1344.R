library(stats)

simulate_geometric_brownian_motion <- function(S0, mu, sigma, T, N) {
  dt <- T / N
  t <- seq(0, T, length.out = N)
  W <- cumsum(rnorm(N)) * sqrt(dt)
  X <- (mu - 0.5 * sigma^2) * t + sigma * W
  S <- S0 * exp(X)
  return(S)
}

monte_carlo_option_pricing <- function(S0, K, T, r, sigma, N, M) {
  option_values <- numeric(M)
  for (i in 1:M) {
    S <- simulate_geometric_brownian_motion(S0, r, sigma, T, N)
    payoff <- pmax(S[N] - K, 0)
    option_values[i] <- payoff
  }
  return(exp(-r * T) * mean(option_values))
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 10000
  result <- monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  print(result)
}

main()