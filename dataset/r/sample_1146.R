simulate_p_value <- function(a, b) {
  merged <- c(a, b)
  merged <- sample(merged)
  observed_diff <- abs(sum(a) - sum(b))
  count <- 0
  for (i in 1:10000) {
    merged <- sample(merged)
    if (abs(sum(merged[1:length(a)]) - sum(merged[(length(a) + 1):length(merged)])) >= observed_diff) {
      count <- count + 1
    }
  }
  return(count / 10000)
}

recursive_permutation_test <- function(data, a, b) {
  if (length(data) == 0) {
    return(simulate_p_value(a, b))
  } else {
    element <- data[length(data)]
    data <- data[-length(data)]
    a <- c(a, element)
    p_value_a <- recursive_permutation_test(data, a, b)
    a <- a[-length(a)]
    b <- c(b, element)
    p_value_b <- recursive_permutation_test(data, a, b)
    b <- b[-length(b)]
    return(max(p_value_a, p_value_b))
  }
}

main <- function() {
  data <- sample(1:100, 20, replace = TRUE)
  a <- c()
  b <- c()
  while (TRUE) {
    p_value <- recursive_permutation_test(data, a, b)
    print(p_value)
  }
}

main()