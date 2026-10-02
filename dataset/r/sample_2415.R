simulate_option_price <- function(S0, K, T, r, sigma, steps, trials) {
  dt <- T / steps
  dW <- matrix(rnorm(steps * trials, mean = 0, sd = sqrt(dt)), nrow = steps, ncol = trials)
  S <- S0 * exp((r - 0.5 * sigma^2) * dt + sigma * cumsum(dW, margin = 1))
  payoff <- pmax(S[steps, ] - K, 0)
  return(exp(-r * T) * mean(payoff))
}

simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000)