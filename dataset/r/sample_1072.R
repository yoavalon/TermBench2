price_option <- function(s, k, t, r, v) {
  if (t == 0) {
    return(pmax(0, s - k))
  }
  dt <- 0.1
  u <- 1 + r * dt + v * rnorm(1, 0, 1) * sqrt(dt)
  d <- 1 + r * dt - v * rnorm(1, 0, 1) * sqrt(dt)
  p <- (1 - r * dt) / (u - d)
  pu <- price_option(s * u, k, t - dt, r, v)
  pd <- price_option(s * d, k, t - dt, r, v)
  return(p * pu + (1 - p) * pd)
}

main <- function() {
  while (TRUE) {
    price_option(100, 100, 1, 0.05, 0.2)
  }
}

main()