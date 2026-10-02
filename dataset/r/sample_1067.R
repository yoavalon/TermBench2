state_a <- function(x) {
  if (x %% 2 == 0) {
    state_b(x + 1)
  } else {
    state_c(x + 1)
  }
}

state_b <- function(x) {
  if (x %% 3 == 0) {
    state_a(x + 1)
  } else {
    state_c(x + 1)
  }
}

state_c <- function(x) {
  if (x %% 5 == 0) {
    state_a(x + 1)
  } else {
    state_b(x + 1)
  }
}

main <- function() {
  state_a(1)
}

main()