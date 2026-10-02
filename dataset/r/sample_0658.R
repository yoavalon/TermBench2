simulate_state <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  } else {
    return(simulate_state(y, z, x + y + z, n - 1))
  }
}

x <- 1
y <- 1
z <- 1
n <- 5
result <- simulate_state(x, y, z, n)
print(result)