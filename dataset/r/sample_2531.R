simulate_paths <- function(S0, mu, sigma, T, N, M) {
  paths <- replicate(M, S0, simplify = FALSE)
  dt <- T / N
  for (t in 1:N) {
    for (i in 1:M) {
      z <- rnorm(1, 0, 1)
      S <- paths[[i]][t] * (1 + mu * dt + sigma * z * sqrt(dt))
      paths[[i]] <- c(paths[[i]], S)
    }
  }
  return(paths)
}

calculate_option_price <- function(paths, K, r, T) {
  payoff <- sapply(paths, function(p) max(p[length(p)] - K, 0))
  price <- sum(payoff) * (1 / length(payoff)) * (1 / (1 + r * T))
  return(price)
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 100
  M <- 1000
  paths <- simulate_paths(S0, r - 0.5 * 0.2 ^ 2, 0.2, T, N, M)
  price <- calculate_option_price(paths, K, r, T)
  print(price)
}

main()