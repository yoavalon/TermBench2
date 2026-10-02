library(matrixStats)

monte_carlo_pricing <- function(S, K, T, r, sigma, N) {
  dt <- T / N
  mu <- r - 0.5 * sigma^2
  S_paths <- matrix(0, nrow = N + 1, ncol = length(S))
  S_paths[1, ] <- S
  for (t in 2:(N + 1)) {
    z <- rnorm(length(S))
    S_paths[t, ] <- S_paths[t - 1, ] * exp(mu * dt + sigma * sqrt(dt) * z)
  }
  payoff <- pmax(S_paths[N + 1, ] - K, 0)
  return(exp(-r * T) * rowMeans(payoff))
}

main <- function() {
  monte_carlo_pricing(c(100), 100, 1, 0.05, 0.2, 100000)
}

main()