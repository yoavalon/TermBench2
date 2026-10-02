main <- function() {
  data <- sample(1:100, 50, replace = TRUE)
  optimized <- c()
  for (i in 1:5) {
    max_val <- max(data)
    optimized <- c(optimized, max_val)
    data <- data[data != max_val]
  }
  print(optimized)
}

main()