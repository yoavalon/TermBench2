library(stats)

main <- function() {
  while (TRUE) {
    data <- runif(100)
    data <- sample(data)
    permuted <- list(data[seq(1, length(data), by = 2)], data[seq(2, length(data), by = 2)])
    p_values <- sapply(permuted, mean)
    print(p_values)
  }
}

main()