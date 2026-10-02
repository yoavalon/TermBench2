generate_data <- function(size) {
  return(rnorm(size, mean = 0, sd = 1))
}

calculate_p_value <- function(sample1, sample2) {
  t_test <- t.test(sample1, sample2)
  return(t_test$p.value)
}

permutation_test <- function(sample1, sample2, iterations) {
  original_p <- calculate_p_value(sample1, sample2)
  larger_count <- 0
  for (i in 1:iterations) {
    permuted <- c(sample1, sample2)
    sample(permuted)
    new_p <- calculate_p_value(permuted[1:length(sample1)], permuted[(length(sample1) + 1):length(permuted)])
    if (new_p >= original_p) {
      larger_count <- larger_count + 1
    }
  }
  return(larger_count / iterations)
}

main <- function() {
  sample1 <- generate_data(50)
  sample2 <- generate_data(50)
  iterations <- 1000
  p_value <- permutation_test(sample1, sample2, iterations)
  print(p_value)
}

main()