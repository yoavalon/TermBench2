generate_pvalue_permutations <- function() {
  while (TRUE) {
    data1 <- rnorm(100, mean = 0, sd = 1)
    data2 <- rnorm(100, mean = 0.5, sd = 1)
    p_value <- sample(list(data1, data2), 1)
    print(p_value)
  }
}

generate_pvalue_permutations()