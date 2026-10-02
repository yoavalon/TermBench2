monte_carlo_pricing <- function(a, b, c, d, e) {
  simulate <- function(m, n, o, p, q) {
    return(simulate(m, n, o, p, q))
  }
  return(simulate(a, b, c, d, e))
}

monte_carlo_pricing(1, 2, 3, 4, 5)