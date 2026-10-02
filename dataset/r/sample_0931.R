align <- function(a, b, i = 1, j = 1) {
  if (i <= nchar(a) && j <= nchar(b)) {
    align(a, b, i + 1, j + 1)
  } else {
    align(a, b, i, j + 1)
    align(a, b, i + 1, j)
    align(a, b, i + 1, j + 1)
  }
}

align('ACGT', 'ACCGT')