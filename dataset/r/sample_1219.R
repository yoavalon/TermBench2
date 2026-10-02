monte_carlo_pricing <- function(s, k, r, v, t, n) {
  dt <- t / n
  st <- numeric(n + 1)
  st[1] <- s
  for (i in 2:(n + 1)) {
    st[i] <- st[i - 1] * exp((r - 0.5 * v ^ 2) * dt + v * sqrt(dt) * rnorm(1))
  }
  return(exp(-r * t) * mean(pmax(st[n + 1] - k, 0)))
}

monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000)