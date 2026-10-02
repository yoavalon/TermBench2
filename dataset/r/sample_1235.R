run <- function() {
  data <- runif(100)
  test_stat <- mean(data)
  p_values <- replicate(1000, {
    sum(runif(100) < test_stat) / 100
  })
  print(max(p_values))
}

run()