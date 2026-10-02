monte_carlo_price <- function(s, k, r, t, v, n, simulations) {
  simulate <- function() {
    price <- s
    for (i in 1:n) {
      price <- price * (1 + rnorm(1, mean = r - v^2 / 2, sd = v))
    }
    return(max(price - k, 0))
  }
  return(sum(sapply(1:simulations, function(x) simulate())) / simulations)
}

monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000)