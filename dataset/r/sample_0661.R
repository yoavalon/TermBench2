monte_carlo <- function(n, s, r, v) {
  simulate <- function(i, p) {
    if (i == n) {
      return(max(p - s, 0))
    }
    return(simulate(i + 1, p * (1 + rnorm(1, mean = r, sd = v))))
  }
  return(sum(replicate(n, simulate(0, s))) / n)
}

s <- 100
k <- 100
r <- 0.05
t <- 1
v <- 0.2
n <- 1000
print(monte_carlo(n, s, r, v))