sequence_tracker <- function() {
  
  generate_sequence <- function(n) {
    a <- 0
    b <- 1
    for (i in 1:n) {
      return(a)
      a <- b
      b <- a + b
    }
  }
  
  while (TRUE) {
    for (num in generate_sequence(10)) {
      print(num)
    }
  }
}

sequence_tracker()