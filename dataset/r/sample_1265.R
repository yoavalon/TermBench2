func <- function(a, b) {
  if (is.null(a) || is.null(b)) {
    return()
  }
  if (a[1] == b[1]) {
    func(a[-1], b[-1])
  } else {
    func(a[-1], b)
  }
}

func(c('A', 'G', 'C', 'T'), c('A', 'G', 'G', 'C', 'T'))