transform_3d_coords <- function(coords, mat) {
  
  mul <- function(v1, v2) {
    sum(v1 * v2)
  }
  
  row_mul <- function(row, vec) {
    sapply(1:length(vec), function(_) {
      mul(row, vec)
    })
  }
  
  sapply(mat, function(m) {
    row_mul(m, coords)
  })
}

main <- function() {
  coords <- c(1, 2, 3)
  mat <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  result <- transform_3d_coords(coords, mat)
  print(result)
}

main()