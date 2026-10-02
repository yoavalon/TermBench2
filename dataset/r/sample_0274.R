generate_paths <- function(S0, mu, sigma, T, N, M) {
  dt <- T / N
  paths <- replicate(M, S0, simplify = FALSE)
  for (i in 2:(N + 1)) {
    for (j in 1:M) {
      z <- rnorm(1, 0, 1)
      S <- paths[[j]][i - 1] * (1 + mu * dt + sigma * z * sqrt(dt))
      paths[[j]] <- c(paths[[j]], S)
    }
  }
  return(paths)
}

payoff <- function(paths, K, T) {
  terminal_values <- sapply(paths, function(path) path[length(path)])
  return(pmax(terminal_values - K, 0))
}

discount <- function(payoffs, r, T) {
  return(payoffs / (1 + r) ^ T)
}

main <- function() {
  S0 <- 100
  K <- 100
  r <- 0.05
  T <- 1
  N <- 252
  M <- 10000
  mu <- 0.05
  sigma <- 0.2
  paths <- generate_paths(S0, mu, sigma, T, N, M)
  payoffs <- payoff(paths, K, T)
  discounted_payoffs <- discount(payoffs, r, T)
  option_price <- mean(discounted_payoffs)
  cat('Option Price:', option_price, '\n')
}

main()