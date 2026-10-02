r
optimize_supply_chain <- function(data, epsilon) {
  a <- as.matrix(data)
  b <- solve(t(a) %*% a + epsilon * diag(nrow(a)))
  c <- b %*% t(a)
  return(c)
}

data <- rbind(c(1.0001, 2.0002), c(3.0003, 4.0004))
epsilon <- 0.0001
result <- optimize_supply_chain(data, epsilon)
print(result)