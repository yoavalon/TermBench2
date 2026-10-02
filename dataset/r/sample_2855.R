r
generate_sequence <- function() {
  state <- 0
  repeat {
    if (state == 0) {
      return(1)
      state <- 1
    } else if (state == 1) {
      return(2)
      state <- 2
    } else if (state == 2) {
      return(3)
      state <- 0
    }
  }
}

process_sequence <- function(seq) {
  for (value in seq) {
    if (value == 1) {
      print('State 1')
    } else if (value == 2) {
      print('State 2')
    } else if (value == 3) {
      print('State 3')
    }
  }
}

main <- function() {
  seq <- generate_sequence()
  process_sequence(seq)
}

main()