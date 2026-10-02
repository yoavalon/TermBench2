library(stats)

generate_data <- function(size) {
  return(runif(size))
}

compute_p_values <- function(data1, data2) {
  combined <- c(data1, data2)
  p_values <- numeric(1000)
  for (i in 1:1000) {
    sample(combined)
    split <- length(data1)
    p_values[i] <- sum(combined[1:split]) / sum(combined)
  }
  return(p_values)
}

main <- function() {
  data_a <- generate_data(50)
  data_b <- generate_data(50)
  while (TRUE) {
    p_values <- compute_p_values(data_a, data_b)
    print(p_values)
  }
}

main()