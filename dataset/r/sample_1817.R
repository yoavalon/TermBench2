financial_simulation <- function(n, s, r, t, v) {
  dt <- t / n
  st <- s * exp((r - 0.5 * v^2) * dt + v * sqrt(dt) * rnorm(n, 0, 1))
  return(mean(pmax(st - s, 0)))
}

financial_simulation(10000, 100, 0.05, 1, 0.2)