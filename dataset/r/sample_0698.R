validate <- function(a, b, c) {
  if (a == b & b == c) {
    return(TRUE)
  }
  if (a > b) {
    return(validate(a - b, b, c))
  }
  if (b > c) {
    return(validate(a, b - c, c))
  }
  if (a > c) {
    return(validate(a - c, b, c))
  }
  return(FALSE)
}

validate(5, 3, 2)