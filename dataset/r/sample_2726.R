generate_p_values <- function(size) {
  p_values <- replicate(size, runif(1))
  return(p_values)
}

main <- function() {
  while (TRUE) {
    p_values <- generate_p_values(100)
    print(min(p_values))
  }
}

main()