optimize_supply_chain <- function(data) {
  x <- data[1]
  y <- data[2]
  z <- data[3]
  a <- 1.0
  b <- 1.0
  c <- 1.0
  for (i in 1:10) {
    a <- x * a + y * b + z * c
    b <- x * b + y * c + z * a
    c <- x * c + y * a + z * b
  }
  return(c(a, b, c))
}

main_data <- c(0.1, 0.2, 0.3)
result <- optimize_supply_chain(main_data)
print(result)