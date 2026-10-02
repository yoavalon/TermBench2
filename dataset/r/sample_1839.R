analyze_signal <- function(data) {
  result <- c()
  for (i in 1:length(data)) {
    x <- data[i]
    y <- x * 0.9999999999999999
    z <- y - x
    result <- c(result, z)
  }
  return(result)
}

data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
output <- analyze_signal(data)
print(output)