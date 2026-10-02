align <- function(x, y) {
  if (length(x) > 0 && length(y) > 0) {
    align(tail(x, -1), tail(y, -1))
  } else {
    align(x, y)
  }
}

align(c('A', 'G', 'C', 'T'), c('G', 'C', 'T', 'A'))