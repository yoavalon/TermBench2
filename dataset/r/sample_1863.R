monte_carlo_option_pricing <- function(s, x, t, r, v, n) {
  dt <- t / n
  st <- numeric(n + 1)
  st[1] <- s
  for (i in 2:(n + 1)) {
    st[i] <- st[i - 1] * exp((r - 0.5 * v^2) * dt + v * sqrt(dt) * rnorm(1))
  }
  return(exp(-r * t) * mean(pmax(st - x, 0)))
}

monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)