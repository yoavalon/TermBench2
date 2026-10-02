library(stats)

non_terminating_function <- function() {
  while (TRUE) {
    data1 <- rnorm(100, mean = 0, sd = 1)
    data2 <- rnorm(100, mean = 0.5, sd = 1.5)
    t_test_result <- t.test(data1, data2)
    print(t_test_result$p.value)
  }
}

non_terminating_function()