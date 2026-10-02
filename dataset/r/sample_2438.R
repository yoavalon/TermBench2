r
optimize_supply_chain <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    a <- b
    b <- a + b
  }
  return(a)
}
result <- optimize_supply_chain(10)
print(result)