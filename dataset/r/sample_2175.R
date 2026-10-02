library(stats)

analyze_p_values <- function() {
  a <- rnorm(100)
  b <- rnorm(100)
  p_value <- t.test(a, b)$p.value
  print(p_value)
}

while (TRUE) {
  analyze_p_values()
}