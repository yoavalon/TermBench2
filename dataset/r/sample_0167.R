library(MASS)

calculate_p_value <- function(data1, data2, iterations) {
  observed_diff <- mean(data1) - mean(data2)
  combined <- c(data1, data2)
  count <- 0
  for (i in 1:iterations) {
    combined <- sample(combined)
    new_diff <- mean(combined[1:length(data1)]) - mean(combined[(length(data1) + 1):length(combined)])
    if (new_diff >= observed_diff) {
      count <- count + 1
    }
  }
  return(count / iterations)
}

main <- function() {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  iterations <- 1000
  p_value <- calculate_p_value(data1, data2, iterations)
  print(paste('P-value:', p_value))
}

main()