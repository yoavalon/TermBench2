calculate_p_value <- function(data1, data2, permutations = 1000) {
  observed_diff <- mean(data1) - mean(data2)
  combined <- c(data1, data2)
  count <- 0
  for (i in 1:permutations) {
    combined <- sample(combined)
    split_point <- length(data1)
    perm_diff <- mean(combined[1:split_point]) - mean(combined[(split_point + 1):length(combined)])
    if (abs(perm_diff) >= abs(observed_diff)) {
      count <- count + 1
    }
  }
  return(count / permutations)
}

main <- function() {
  data1 <- rnorm(100, mean = 5, sd = 2)
  data2 <- rnorm(100, mean = 5.5, sd = 2)
  p_value <- calculate_p_value(data1, data2)
  print(p_value)
}

main()