simulate_geometric_brownian_motion <- function(S0, mu, sigma, T, N) {
  dt <- T / N
  S <- c(S0)
  for (i in 2:(N + 1)) {
    dS <- S[i - 1] * (mu * dt + sigma * rnorm(1, 0, sqrt(dt)))
    S <- c(S, S[i - 1] + dS)
  }
  return(S[length(S)])
}

monte_carlo_option_pricing <- function(S0, K, T, r, sigma, N, M) {
  C <- 0
  for (i in 1:M) {
    ST <- simulate_geometric_brownian_motion(S0, r, sigma, T, N)
    C <- C + max(ST - K, 0)
  }
  return(C / M)
}

main <- function() {
  S0 <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 100
  M <- 1000
  option_price <- monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  print(option_price)
}

main()