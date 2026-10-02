library(signal)

mutate_data <- function(data, n) {
  vec <- as.numeric(data)
  for (i in 1:n) {
    vec <- convolve(vec, runif(3), type = "same")
  }
  return(as.list(vec))
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  mutated_data <- mutate_data(data, 5)
  print(mutated_data)
}

main()